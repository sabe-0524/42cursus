/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 20:23:50 by sabe              #+#    #+#             */
/*   Updated: 2025/06/28 16:34:22 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>
#include <limits.h>

static int	ft_isspace(int c)
{
	if ((9 <= c && c <= 13) || c == ' ')
		return (1);
	else
		return (0);
}

static long long int	ft_atoi_exit(const char *str, bool *error)
{
	size_t			count;
	int				flag;
	long long int	answer;
	long long int	tmp;

	count = 0;
	flag = 1;
	answer = 0;
	if (!ft_strcmp(str, "-9223372036854775808"))
		return (LLONG_MIN);
	while (ft_isspace((int)str[count]))
		count++;
	if (str[count] == '-' || str[count] == '+')
	{
		if (str[count++] == '-')
			flag = -1;
	}
	while ('0' <= str[count] && str[count] <= '9')
	{
		tmp = answer;
		answer = answer * 10 + str[count++] - '0';
		if (tmp > answer)
			*error = true;
	}
	return ((answer * flag));
}

bool	is_numeric(t_token *tk)
{
	char	*content;
	size_t	i;

	i = 0;
	content = tk->content;
	if (!content[0])
		return (false);
	while (content[i])
	{
		if (!(('0' <= content[i] && content[i] <= '9') || (i == 0
					&& (content[i] == '-' || content[i] == '+'))))
			return (false);
		i++;
	}
	return (true);
}

void	do_exit(t_executor *ex, int num)
{
	if (ex->pid != 0)
	{
		ft_putendl_fd("exit", ex->out_fd);
		exit(num);
	}
}

int	ex_exit(t_node *node, t_executor *ex)
{
	int		status;
	bool	error;

	error = false;
	if (count_token(node) == 1)
		do_exit(ex, ft_atoi(my_getenv("?", ex->env)));
	else if (!is_numeric(node->token->next))
	{
		ft_putendl_fd("numeric argument required", 2);
		do_exit(ex, 2);
	}
	else if (count_token(node) == 2)
	{
		status = ft_atoi_exit(node->token->next->content, &error) % 256;
		if (error == true)
		{
			ft_putendl_fd("numeric argument required", 2);
			do_exit(ex, 2);
		}
		do_exit(ex, status);
	}
	else
		ft_putendl_fd("exit: too many arguments", 2);
	return (EXIT_FAILURE);
}
