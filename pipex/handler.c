/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:36:31 by abesouichir       #+#    #+#             */
/*   Updated: 2025/03/24 23:43:18 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	make_pipe(int **pipe_fd)
{
	*pipe_fd = (int *)malloc(sizeof(int) * 2);
	if (!*pipe_fd)
	{
		perror(NULL);
		exit(EXIT_FAILURE);
	}
	if (pipe(*pipe_fd) == -1)
	{
		perror(NULL);
		free(*pipe_fd);
		exit(EXIT_FAILURE);
	}
}

void	handle_first(char **argv, int *in_fd, char *path)
{
	int		*pipe_fd;
	pid_t	pid;

	make_pipe(&pipe_fd);
	pid = fork();
	if (pid < 0)
	{
		perror(NULL);
		free(pipe_fd);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
		do_child(argv, 2, pipe_fd, path);
	else
	{
		close(pipe_fd[1]);
		*in_fd = pipe_fd[0];
		free(pipe_fd);
	}
}

void	handle_middle(char **argv, int *in_fd, int index, char *path)
{
	int		*pipe_fd;
	pid_t	pid;

	make_pipe(&pipe_fd);
	pid = fork();
	if (pid < 0)
		handle_pid_error(pipe_fd);
	else if (pid == 0)
	{
		if (*in_fd != STDIN_FILENO)
		{
			dup2(*in_fd, STDIN_FILENO);
			close(*in_fd);
		}
		do_child(argv, index, pipe_fd, path);
	}
	else
	{
		if (*in_fd != STDIN_FILENO)
			close(*in_fd);
		close(pipe_fd[1]);
		*in_fd = pipe_fd[0];
		free(pipe_fd);
	}
}

void	handle_last(int *in_fd, char *outfile_name)
{
	pid_t	pid;
	int		outfile;

	pid = fork();
	if (pid < 0)
	{
		perror(NULL);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (*in_fd != STDIN_FILENO)
		{
			dup2(*in_fd, STDIN_FILENO);
			close(*in_fd);
		}
		outfile = open(outfile_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (outfile < 0)
		{
			perror(NULL);
			exit(EXIT_FAILURE);
		}
		print_fd(outfile_name, outfile);
		exit(0);
	}
}

int	handle_command(int argc, char **argv, char *path)
{
	int	index;
	int	in_fd;
	int	status;
	int	exit_code;

	exit_code = 0;
	index = 3;
	handle_first(argv, &in_fd, path);
	while (index < argc - 1)
	{
		handle_middle(argv, &in_fd, index, path);
		index++;
	}
	handle_last(&in_fd, argv[argc - 1]);
	while (wait(&status) > 0)
	{
		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
			exit_code = WEXITSTATUS(status);
	}
	return (exit_code);
}
