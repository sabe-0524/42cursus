/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:20:32 by sabe              #+#    #+#             */
/*   Updated: 2025/05/14 20:24:43 by sabe             ###   ########.fr       */
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
	int		save_in;
	int		save_out;
	pid_t	pid;
	char	**envp;
}			t_executor;

t_executor	*init_ex(t_tree *tree);
void		ex_command(t_node *node, t_executor *ex);
void		ex_pipe(t_executor *ex);
void		exec(t_tree *tree);
void		ex_command_first(t_node *node, t_executor *ex);
void		recur_ex(t_node *node, t_executor *ex);
void		all_free_paths(char **paths);
char		*make_filepath(char **command);
char		*find_filepath(char *s);
char		**make_shellcommand(t_node *node);
void		ex_greater(t_node *node, t_executor *ex);
void		ex_lesser(t_node *node, t_executor *ex);
void		ex_r_greater(t_node *node, t_executor *ex);
void		ex_redirect(t_node *node, t_executor *ex);

#endif
