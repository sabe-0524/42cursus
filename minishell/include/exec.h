/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:20:32 by sabe              #+#    #+#             */
/*   Updated: 2025/05/10 18:12:04 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include <fcntl.h>
# include <parser.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_executor
{
	t_tree	*tree;
	int		pipe_fd[2];
	int		in_fd;
	int		out_fd;
	pid_t	pid;
}			t_executor;

t_executor	*init_ex(t_tree *tree);

#endif
