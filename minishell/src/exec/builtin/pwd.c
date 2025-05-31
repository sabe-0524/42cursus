/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:28:50 by abesouichir       #+#    #+#             */
/*   Updated: 2025/05/31 18:42:28 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

int	ex_pwd(t_executor *ex)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
	{
		perror("getcwd");
		exit(EXIT_FAILURE);
	}
	ft_putendl_fd(pwd, ex->out_fd);
	free(pwd);
	return (EXIT_SUCCESS);
}
