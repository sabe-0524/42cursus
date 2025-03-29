/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:22:20 by sabe              #+#    #+#             */
/*   Updated: 2025/03/29 18:09:22 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_fd(char *outfile_name, int outfile)
{
	int		count;
	char	c;

	if (access(outfile_name, W_OK))
		do_error();
	count = read(STDIN_FILENO, &c, 1);
	while (count > 0)
	{
		write(outfile, &c, 1);
		count = read(STDIN_FILENO, &c, 1);
	}
	close(outfile);
	if (count < 0)
	{
		close(outfile);
		do_error();
	}
}

void	handle_pid_error(int *pipe_fd)
{
	free(pipe_fd);
	do_error();
}

void	error_in_command(char **command, char *filepath)
{
	all_free(command, 0);
	free(filepath);
	do_error();
}

void	do_error(void)
{
	perror(NULL);
	exit(EXIT_FAILURE);
}
