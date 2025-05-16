/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 20:21:05 by sabe              #+#    #+#             */
/*   Updated: 2025/05/16 21:43:59 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

void cd_to_home(t_executor *ex)
{
	char *home;

	home = my_getenv("HOME", ex->env);
	if (!home)
		exit(1); // TODO
	chdir(home);
	my_setenv_row(ex->env, "PWD", home);
}

void cd_to_path(t_node *node, t_executor *ex)
{
	if (chdir(node->token->next->content) == -1)
		perror(NULL);
	my_setenv_row(ex->env, "PWD", getcwd(NULL, 0));
}

void	ex_cd(t_node *node, t_executor *ex)
{
	if (count_token(node) > 2)
		exit(1); // TODO
	else if (count_token(node) == 1)
		cd_to_home(ex);
	else
		cd_to_path(node, ex);
}
