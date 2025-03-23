/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:22:20 by sabe              #+#    #+#             */
/*   Updated: 2025/03/23 17:57:07 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_fd(char *outfile_name)
{
	int		outfile;
	int		count;
	char	c;

	outfile = open(outfile_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
	{
		perror(NULL);
		exit(EXIT_FAILURE);
	}
	count = read(STDIN_FILENO, &c, 1);
	while (count > 0)
	{
		write(outfile, &c, 1);
		count = read(STDIN_FILENO, &c, 1);
	}
	close(outfile);
	if (count < 0)
	{
		perror(NULL);
		close(outfile);
		exit(EXIT_FAILURE);
	}
}

void	handle_pid_error(int *pipe_fd)
{
	perror(NULL);
	free(pipe_fd);
	exit(EXIT_FAILURE);
}
