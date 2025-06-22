/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 20:21:05 by sabe              #+#    #+#             */
/*   Updated: 2025/06/22 18:41:15 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

int	cd_to_home(t_executor *ex)
{
	char	*home;

	home = my_getenv("HOME", ex->env);
	if (!home)
	{
		ft_putendl_fd("Home not set", 2);
		return (EXIT_FAILURE);
	}
	if (chdir(home) == -1)
	{
		perror(NULL);
		return (EXIT_FAILURE);
	}
	my_setenv_row(ex->env, "PWD", home);
	return (EXIT_SUCCESS);
}

int	cd_to_path(t_node *node, t_executor *ex)
{
	if (chdir(node->token->next->content) == -1)
	{
		perror(NULL);
		return (EXIT_FAILURE);
	}
	my_setenv_row(ex->env, "PWD", getcwd(NULL, 0));
	return (EXIT_SUCCESS);
}

int	ex_cd(t_node *node, t_executor *ex)
{
	if (count_token(node) > 2)
	{
		ft_putendl_fd("cd: too many arguments", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	else if (count_token(node) == 1)
		return (cd_to_home(ex));
	else
		return (cd_to_path(node, ex));
}
