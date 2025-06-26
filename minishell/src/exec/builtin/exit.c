/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 20:23:50 by sabe              #+#    #+#             */
/*   Updated: 2025/06/26 21:15:18 by sabe             ###   ########.fr       */
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

static int	ft_atoi_exit(const char *str, bool *error)
{
	size_t			count;
	int				flag;
	long long int	answer;

	count = 0;
	flag = 1;
	answer = 0;
	while (ft_isspace((int)str[count]))
		count++;
	if (str[count] == '-' || str[count] == '+')
	{
		if (str[count] == '-')
			flag = -1;
		count++;
	}
	while ('0' <= str[count] && str[count] <= '9')
	{
		answer *= 10;
		answer += str[count] - '0';
		count++;
		if ((flag == 1 && answer > (long long)INT_MAX) || (flag == -1
				&& answer > (long long)INT_MIN * -1))
			*error = true;
	}
	return ((int)(answer * flag));
}

bool	is_numeric(t_token *tk)
{
	char	*content;
	size_t	i;

	i = 0;
	content = tk->content;
	while (content[i])
	{
		if (!(('0' <= content[i] && content[i] <= '9') || (i == 0
					&& (content[i] == '-' || content[i] == '+'))))
			return (false);
		i++;
	}
	return (true);
}

int	ex_exit(t_node *node, t_executor *ex)
{
	int		status;
	bool	error;

	error = false;
	ft_putendl_fd("exit", 2);
	if (count_token(node) == 1)
		exit(ft_atoi(my_getenv("?", ex->env)));
	else if (!is_numeric(node->token->next))
	{
		ft_putendl_fd("numeric argument required", 2);
		exit(2);
	}
	else if (count_token(node) == 2)
	{
		status = ft_atoi_exit(node->token->next->content, &error) % 256;
		if (error == true)
		{
			ft_putendl_fd("numeric argument required", 2);
			exit(2);
		}
		exit(status);
	}
	else
		ft_putendl_fd("exit: too many arguments", 2);
	return (EXIT_FAILURE);
}
