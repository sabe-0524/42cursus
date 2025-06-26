/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 18:26:29 by sabe              #+#    #+#             */
/*   Updated: 2025/06/26 20:38:03 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

char	*make_tmpfile(void)
{
	char	*tmpfile;
	char	*head;
	int		idx;

	idx = 0;
	while (true)
	{
		head = ft_strdup("/tmp/tmpfile_heredoc_");
		tmpfile = ft_strjoin_free(head, make_idx(idx));
		if (access(tmpfile, F_OK) != 0)
			return (tmpfile);
		free(tmpfile);
		idx++;
	}
	return (NULL);
}

int	heredoc_parent(t_executor *ex, pid_t pid, char *tmp_file, int fd)
{
	int status, code = 0;
	parent_signal();
	if (waitpid(pid, &status, 0) < 0)
	{
		perror("waitpid");
		code = 1;
	}
	else if (WIFSIGNALED(status))
	{
		code = 128 + WTERMSIG(status);
	}
	else if (WIFEXITED(status))
	{
		code = WEXITSTATUS(status);
	}
	my_setenv_row(ex->env, "?", ft_itoa(code));
	close(fd);
	if (code != 0)
		unlink(tmp_file);
	return (code);
}

void	heredoc_child(char *delim, int write_fd)
{
	char	*line;

	heredoc_signal();
	while (1)
	{
		line = readline("> ");
		if (g_signal == 1)
			break ;
		if (!line)
			break ;
		if (ft_strcmp(line, delim) == 0)
		{
			free(line);
			break ;
		}
		ft_putendl_fd(line, write_fd);
		free(line);
	}
	rl_clear_history();
	close(write_fd);
	if (g_signal == 1)
	{
		g_signal = 0;
		exit(130);
	}
	exit(0);
}

int	add_heredoc_fd(t_executor *ex, t_node *node)
{
	int		fd;
	char	*tmpfile;
	pid_t	pid;
	int		status;

	tmpfile = make_tmpfile();
	fd = open(tmpfile, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	pid = my_fork();
	if (pid == 0)
	{
		heredoc_child(node->left->token->content, fd);
		return (1);
	}
	else
	{
		status = heredoc_parent(ex, pid, tmpfile, fd);
		if (status == 0)
		{
			node->heredoc_tmpfile = tmpfile;
			return (status);
		}
		else
		{
			free(tmpfile);
			return (status);
		}
	}
}

void	exec_heredoc(t_executor *ex, t_node *node, int *status)
{
	if (*status != 0 || node == NULL)
		return ;
	exec_heredoc(ex, node->left, status);
	if (node->token->type == R_LESSER)
	{
		*status = add_heredoc_fd(ex, node);
	}
	exec_heredoc(ex, node->right, status);
}
