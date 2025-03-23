/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:28:31 by abesouichir       #+#    #+#             */
/*   Updated: 2025/03/23 17:29:08 by sabe             ###   ########.fr       */
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

void	handle_command(int argc, char **argv);
char	**make_command(char **argv, int index);
char	*make_filepath(char **command);
void	do_command(char **argv, int index);
void	do_child(char **argv, int index, int *pipe_fd);
void	print_fd(char *outfile_name);
void	handle_pid_error(int *pipe_fd);

#endif
