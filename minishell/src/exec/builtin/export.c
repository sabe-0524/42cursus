/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:52:30 by sabe              #+#    #+#             */
/*   Updated: 2025/06/27 19:15:42 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

void	put_export(char **envp, t_executor *ex)
{
	size_t	i;

	i = 0;
	while (envp[i])
	{
		if (envp[i][0] != '?' && ft_strncmp(envp[i], "_=", 2))
		{
			ft_putstr_fd("declare -x ", ex->out_fd);
			ft_putendl_fd(envp[i], ex->out_fd);
		}
		i++;
	}
}

int	ex_export(t_node *node, t_executor *ex)
{
	t_token	*tk;
	int		flag;
	char	**envp;

	flag = 0;
	tk = node->token->next;
	if (!tk)
	{
		envp = catenv(ex->env);
		put_export(envp, ex);
		all_free_paths(envp);
	}
	while (tk)
	{
		if (my_setenv(ex->env, tk->content) == 1)
			flag = 1;
		tk = tk->next;
	}
	return (flag);
}
