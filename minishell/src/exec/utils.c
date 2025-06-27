/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:42:03 by sabe              #+#    #+#             */
/*   Updated: 2025/06/27 16:37:14 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>
#include <expander.h>

void	all_free_paths(char **paths)
{
	size_t	i;

	i = 0;
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	free(paths);
}

bool	is_dir(char *path)
{
	struct stat	st;

	if (stat(path, &st) != 0)
		return (false);
	if (S_ISDIR(st.st_mode))
		return (true);
	else
		return (false);
}

char	*make_idx(int n)
{
	char	*idx;
	int		i;

	idx = (char *)malloc(sizeof(char) * 11);
	i = 9;
	idx[10] = '\0';
	while (i >= 0)
	{
		idx[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	return (idx);
}

pid_t	my_fork(void)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit(1);
	}
	return (pid);
}

t_command	*make_heredoc_command(char *line, t_expander *ex)
{
	t_command	*new;

	new = (t_command *)ft_calloc(1, sizeof(t_command));
	if (!new)
	{
		exit(1);
	}
	new->content = ft_substr(line, (unsigned int)ex->start_i,
			(size_t)(ex->line_i - ex->start_i));
	if (!new->content)
	{
		exit(1);
	}
	new->is_env = false;
	ex->start_i = ex->line_i;
	return (new);
}
