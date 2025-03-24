/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:28:31 by abesouichir       #+#    #+#             */
/*   Updated: 2025/03/24 23:45:49 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <fcntl.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

int		handle_command(int argc, char **argv, char *path);
char	**make_command(char **argv, int index);
char	*make_filepath(char **command, char *path);
void	do_command(char **argv, int index, char *path);
void	do_child(char **argv, int index, int *pipe_fd, char *path);
void	print_fd(char *outfile_name, int outfile);
void	handle_pid_error(int *pipe_fd);

#endif
