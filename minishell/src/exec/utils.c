/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:42:03 by sabe              #+#    #+#             */
/*   Updated: 2025/06/26 20:32:40 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

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

char *make_idx(int n)
{
	char *idx;
	int i;

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


