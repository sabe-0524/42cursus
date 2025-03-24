/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:35:07 by abesouichir       #+#    #+#             */
/*   Updated: 2025/03/24 23:42:10 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char *get_path(char **envp)
{
  int i;

  i = 0;
  while (envp[i] != NULL)
  {
    if (ft_strncmp(envp[i], "PATH=", 5) == 0)
      return (envp[i] + 5);
    i++;
  }
  return (NULL);
}

int	main(int argc, char **argv, char **envp)
{
  char *path;
  
	if (argc < 5)
		return (1);
  path = get_path(envp);
  if (!path)
  {
    perror(NULL);
    return (1);
  }
	return (handle_command(argc, argv, path));
}
