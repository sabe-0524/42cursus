/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_r_lesser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 19:44:16 by sabe              #+#    #+#             */
/*   Updated: 2025/06/26 20:36:10 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>
// #include <fcntl.h>
// #include <unistd.h>

// void	heredoc_child_loop(const char *delim, int write_fd)
// {
// 	char	*line;

// 	while (1)
// 	{
// 		line = readline("> ");
// 		if (g_signal == 1)
// 			break ;
// 		if (!line)
// 			break ;
// 		if (ft_strcmp(line, delim) == 0)
// 		{
// 			free(line);
// 			break ;
// 		}
// 		ft_putendl_fd(line, write_fd);
// 		free(line);
// 	}
// 	rl_clear_history();
// 	close(write_fd);
// 	if (g_signal == 1)
// 	{
// 		g_signal = 0;
// 		exit(130);
// 	}
// 	exit(0);
// }

// static pid_t	ex_r_lesser_fork(void)
// {
// 	pid_t	pid;

// 	pid = fork();
// 	if (pid < 0)
// 	{
// 		perror("fork");
// 		exit(1);
// 	}
// 	return (pid);
// }

// static int	ex_r_lesser_child(t_node *node, char *tmp_file)
// {
// 	int	fd;

// 	fd = open(tmp_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	if (fd < 0)
// 	{
// 		perror("open");
// 		exit(1);
// 	}
// 	heredoc_signal();
// 	heredoc_child_loop(node->left->token->content, fd);
// 	return (0);
// }

// static int	ex_r_lesser_parent(t_executor *ex, pid_t pid, char *tmp_file)
// {
// 	int	status;

// 	signal(SIGINT, SIG_IGN);
// 	waitpid(pid, &status, 0);
// 	if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
// 	{
// 		ex->in_fd = open(tmp_file, O_RDONLY);
// 		if (ex->in_fd < 0)
// 		{
// 			perror("open");
// 			return (1);
// 		}
// 		return (0);
// 	}
// 	return (130);
// }

// int	ex_r_lesser(t_node *node, t_executor *ex)
// {
// 	pid_t	pid;
// 	char	*tmp_file;
// 	int	fd;

// 	tmp_file = ft_strdup("/tmp/minishell_heredoc_XXXXXX");
// 	if (!tmp_file)
// 		exit(1);
// 	fd = mkstemp(tmp_file);
// 	if (fd < 0)
// 	{
// 		perror("mkstemp");
// 		free(tmp_file);
// 		exit(1);
// 	}
// 	close(fd);
// 	pid = ex_r_lesser_fork();
// 	if (pid == 0)
// 		return (ex_r_lesser_child(node, tmp_file));
// 	else
// 		return (ex_r_lesser_parent(ex, pid, tmp_file));
// }

int	ex_r_lesser(t_node *node, t_executor *ex)
{
	int	fd;

	if (ex->in_fd != STDIN_FILENO)
		close(ex->in_fd);
	fd = open(node->heredoc_tmpfile, O_RDONLY);
	unlink(node->heredoc_tmpfile);
	free(node->heredoc_tmpfile);
	if (fd == -1)
	{
		perror(NULL);
		return (EXIT_FAILURE);
	}
	ex->in_fd = fd;
	return (EXIT_SUCCESS);
}
