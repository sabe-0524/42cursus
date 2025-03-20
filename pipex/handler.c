/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:36:31 by abesouichir       #+#    #+#             */
/*   Updated: 2025/03/17 21:48:21 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	make_pipe(int **pipe_fd)
{
	*pipe_fd = (int *)malloc(sizeof(int) * 2);
	if (!*pipe_fd)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	if (pipe(*pipe_fd) == -1)
	{
		perror("pipe");
		free(*pipe_fd);
		exit(EXIT_FAILURE);
	}
}

void	handle_first(char **argv, int *in_fd)
{
	int		*pipe_fd;
	pid_t	pid;

	make_pipe(&pipe_fd);
	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		free(pipe_fd);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
		do_child(argv, 2, pipe_fd);
	else
	{
		close(pipe_fd[1]);
		*in_fd = pipe_fd[0];
		free(pipe_fd);
	}
}

void	handle_middle(char **argv, int *in_fd, int index)
{
	int		*pipe_fd;
	pid_t	pid;

	make_pipe(&pipe_fd);
	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		free(pipe_fd);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (*in_fd != STDIN_FILENO)
		{
			dup2(*in_fd, STDIN_FILENO);
			close(*in_fd);
		}
		do_child(argv, index, pipe_fd);
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

void	handle_last(int *in_fd, int outfile)
{
	char	c;
	int		count;
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (*in_fd != STDIN_FILENO)
		{
			dup2(*in_fd, STDIN_FILENO);
			close(*in_fd);
		}
		count = read(STDIN_FILENO, &c, 1);
		while (count > 0)
		{
			write(outfile, &c, 1);
			count = read(STDIN_FILENO, &c, 1);
		}
		if (count < 0)
		{
			perror("read");
			exit(EXIT_FAILURE);
		}
		exit(0);
	}
}

void	handle_command(int argc, char **argv, int outfile)
{
	int	index;
	int	in_fd;

	index = 3;
	handle_first(argv, &in_fd);
	while (index < argc - 1)
	{
		handle_middle(argv, &in_fd, index);
		index++;
	}
	handle_last(&in_fd, outfile);
	while (wait(NULL) > 0)
		;
}
