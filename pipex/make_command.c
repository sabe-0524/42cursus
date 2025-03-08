/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:08:48 by abesouichir       #+#    #+#             */
/*   Updated: 2025/03/08 18:18:58 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
extern char **environ;

void all_free(char **paths, int i)
{
    while (paths[i] != NULL)
    {
        free(paths[i]);
        paths[i] = NULL;
        i++;
    }
    free(paths);
}

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

char *get_first(char *full_command)
{
    char **splited_command;
    char *command;

    splited_command = ft_split(full_command, ' ');
    command = splited_command[0];
    all_free(splited_command, 1);
    if (ft_strchr(command, '/'))
    {
        if (access(command, X_OK) == 0)
            return (command);
        else
            {}//エラー処理
    }
    free(command);
    return (NULL);
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
            all_free(paths, 0);
            return (path);
        }
        free(path);
        i++;
    }
    return (NULL);//フリーしてexitすべき
}


void do_command(char **argv, int index)
{
    char **command;
    char *filepath;
    char *tmp;

    command = make_command(argv, index);
    if (ft_strchr(command[0], '/'))
    {
        filepath = ft_strdup(command[0]);
        if (access(filepath, X_OK) != 0)
        {
            //エラー処理exit
        }
        tmp = ft_strdup(ft_strrchr(command[0], '/') + 1);
        free(command[0]);
        command[0] = tmp;
    }
    else
        filepath = make_filepath(command);
    execve(filepath, command, environ);
    perror("execve");
    exit(EXIT_FAILURE);
}