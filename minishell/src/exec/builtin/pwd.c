/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:28:50 by abesouichir       #+#    #+#             */
/*   Updated: 2025/05/16 18:30:23 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

void ex_pwd(t_executor *ex)
{
  char	*pwd;

  pwd = getcwd(NULL, 0);
  if (pwd == NULL)
  {
    perror("getcwd");
    exit(EXIT_FAILURE);
  }
  ft_putstrendl_fd(pwd, ex->out_fd);
  free(pwd);
}