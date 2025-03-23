/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_child.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:08:48 by abesouichir       #+#    #+#             */
/*   Updated: 2025/03/23 17:45:37 by sabe             ###   ########.fr       */
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
		tmp = ft_strjoin(argv[index], " ");
		if (access(argv[1], R_OK))
		{
			perror(NULL);
			exit(EXIT_FAILURE);
		}
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

char	*make_filepath(char **command)
{
	char	**paths;
	char	*path;
	char	*tmp;
	int		i;

	i = -1;
	paths = ft_split(getenv("PATH"), ':');
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
	all_free(paths, 1);
	ft_putendl_fd("command not found", 2);
	exit(127);
}

void	do_command(char **argv, int index)
{
	char	**command;
	char	*filepath;
	char	*tmp;

	command = make_command(argv, index);
	if (ft_strchr(command[0], '/'))
	{
		filepath = ft_strdup(command[0]);
		if (access(filepath, X_OK) != 0)
		{
			perror(NULL);
			exit(EXIT_FAILURE);
		}
		tmp = ft_strdup(ft_strrchr(command[0], '/') + 1);
		free(command[0]);
		command[0] = tmp;
	}
	else
		filepath = make_filepath(command);
	execve(filepath, command, environ);
	perror(NULL);
	exit(EXIT_FAILURE);
}

void	do_child(char **argv, int index, int *pipe_fd)
{
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	free(pipe_fd);
	do_command(argv, index);
}
