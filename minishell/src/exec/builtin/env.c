/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:22:25 by abesouichir       #+#    #+#             */
/*   Updated: 2025/05/16 18:24:20 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

void ex_env(t_executor *ex)
{
  char	**envp;
  size_t	i;

  envp = catenv(ex->env);
  i = 0;
  while (envp[i])
  {
    ft_putendl_fd(envp[i], ex->out_fd);
    i++;
  }
  all_free_paths(envp);
}