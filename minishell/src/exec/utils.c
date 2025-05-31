/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:42:03 by sabe              #+#    #+#             */
/*   Updated: 2025/05/31 18:44:05 by sabe             ###   ########.fr       */
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
