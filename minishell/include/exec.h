/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:20:32 by sabe              #+#    #+#             */
/*   Updated: 2025/05/18 16:45:58 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include <env.h>
# include <fcntl.h>
# include <minishell.h>
# include <minisig.h>
# include <parser.h>
# include <readline/readline.h>
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
	t_env	*env;
}			t_executor;

t_executor	*init_ex(t_tree *tree, t_env *env);
void		ex_command(t_node *node, t_executor *ex);
void		ex_pipe(t_executor *ex);
void		exec(t_tree *tree, t_env *env);
void		ex_command_first(t_node *node, t_executor *ex);
void		recur_ex(t_node *node, t_executor *ex);
void		all_free_paths(char **paths);
char		*make_filepath(char **command, t_executor *ex);
char		*find_filepath(char *s, t_executor *ex);
char		**make_shellcommand(t_node *node);
void		ex_greater(t_node *node, t_executor *ex);
void		ex_lesser(t_node *node, t_executor *ex);
void		ex_r_greater(t_node *node, t_executor *ex);
void		ex_redirect(t_node *node, t_executor *ex);
int			ex_r_lesser(t_node *node, t_executor *ex);
int			ex_echo(t_node *node, t_executor *ex);
bool		is_builtin(t_node *node);
int			ex_builtin(t_node *node, t_executor *ex);
int			ex_export(t_node *node, t_executor *ex);
int			ex_unset(t_node *node, t_executor *ex);
int			ex_env(t_executor *ex);
int			ex_pwd(t_executor *ex);
size_t		count_token(t_node *node);
int			ex_cd(t_node *node, t_executor *ex);
int			ex_exit(t_node *node, t_executor *ex);

#endif
