/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:08:48 by abesouichir       #+#    #+#             */
/*   Updated: 2025/03/06 22:44:49 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char **make_command(char **argv, int index)
{
    char *tmp;
    char *str;
    char **command;
  
    if (index == 2)
    {
        tmp = ft_strjoin(argv[index], " ");
        str = ft_strjoin(tmp, argv[1]);
        free(tmp);
    }
    else
        str = argv[index];
    command = ft_split(str, ' ');
    if (index == 2)
        free(str);
    return (command);
}

char *make_filepath(char **command)
{
    char *filepath;

    filepath = ft_strjoin("/bin/", command[0]);
    return (filepath);
}