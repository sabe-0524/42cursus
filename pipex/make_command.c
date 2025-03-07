/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:08:48 by abesouichir       #+#    #+#             */
/*   Updated: 2025/03/07 14:10:52 by abesouichir      ###   ########.fr       */
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

void all_free(char **paths)
{
    int i;

    i = 0;
    while (paths[i] != NULL)
    {
        paths[i] = NULL;
        free(paths[i]);
        i++;
    }
    free(paths);
}

char *make_filepath(char **command)
{
    char **paths;
    char *path;
    char *tmp;
    int i;

    i = 0;
    paths = ft_split(getenv("PATH"), ':');
    while (paths[i] != NULL)
    {
        tmp = ft_strjoin(paths[i], "/");
        path = ft_strjoin(tmp, command[0]);
        free(tmp);
        if (access(path, X_OK) == 0)
        {
            all_free(paths);
            return (path);
        }
        free(path);
        i++;
    }
    return (NULL);
}

// char *make_filepath(char **command)
// {
//     char *filepath;

//     filepath = ft_strjoin("/bin/", command[0]);
//     return (filepath);
// }