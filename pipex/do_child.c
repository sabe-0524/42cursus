/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_child.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:08:48 by abesouichir       #+#    #+#             */
/*   Updated: 2025/03/29 18:07:28 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

extern char	**environ;

void	all_free(char **paths, int i)
{
	while (paths[i] != NULL)
	{
		free(paths[i]);
		paths[i] = NULL;
		i++;
	}
	free(paths);
}

char	**make_command(char **argv, int index)
{
	char	*tmp;
	char	*str;
	char	**command;

	if (index == 2)
	{
		if (access(argv[1], R_OK))
			do_error();
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

char	*make_filepath(char **command, char *path)
{
	char	**paths;
	char	*tmp;
	int		i;

	i = -1;
	paths = ft_split(path, ':');
	while (paths[++i] != NULL)
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
	}
	all_free(paths, 0);
	all_free(command, 0);
	ft_putendl_fd("command not found", 2);
	exit(127);
}

void	do_command(char **argv, int index, char *path)
{
	char	**command;
	char	*filepath;
	char	*tmp;

	command = make_command(argv, index);
	if (ft_strchr(command[0], '/'))
	{
		filepath = ft_strdup(command[0]);
		if (access(filepath, X_OK) != 0)
			error_in_command(command, filepath);
		tmp = ft_strdup(ft_strrchr(command[0], '/') + 1);
		free(command[0]);
		command[0] = tmp;
	}
	else
		filepath = make_filepath(command, path);
	execve(filepath, command, environ);
	error_in_command(command, filepath);
}

void	do_child(char **argv, int index, int *pipe_fd, char *path)
{
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	free(pipe_fd);
	do_command(argv, index, path);
}
