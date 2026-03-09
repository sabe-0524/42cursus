/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 00:00:00 by sabe              #+#    #+#             */
/*   Updated: 2026/03/10 00:00:00 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	read_and_store(int fd, char **save)
{
	char	*buffer;
	int		read_bytes;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (-1);
	read_bytes = 1;
	while (read_bytes > 0 && !ft_strchr(*save, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes < 0)
			return (free(buffer), free(*save), *save = NULL, -1);
		buffer[read_bytes] = '\0';
		*save = ft_strjoin(*save, buffer);
		if (!*save)
			return (free(buffer), -1);
	}
	free(buffer);
	return (read_bytes);
}

static char	*extract_line(char *save)
{
	size_t	len;
	char	*line;

	len = 0;
	if (!save || !save[0])
		return (NULL);
	while (save[len] && save[len] != '\n')
		len++;
	if (save[len] == '\n')
		len++;
	line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	len = 0;
	while (save[len] && save[len] != '\n')
	{
		line[len] = save[len];
		len++;
	}
	if (save[len] == '\n')
		line[len++] = '\n';
	line[len] = '\0';
	return (line);
}

static char	*trim_save(char *save)
{
	size_t	i;
	size_t	j;
	char	*next_save;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i] || !save[i + 1])
		return (free(save), NULL);
	next_save = malloc(sizeof(char) * (ft_strlen(save + i + 1) + 1));
	if (!next_save)
		return (free(save), NULL);
	i++;
	j = 0;
	while (save[i])
		next_save[j++] = save[i++];
	next_save[j] = '\0';
	free(save);
	return (next_save);
}

char	*get_next_line(int fd)
{
	static char	*save[OPEN_MAX];
	char		*line;
	int			status;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	status = read_and_store(fd, &save[fd]);
	if (status < 0)
		return (NULL);
	line = extract_line(save[fd]);
	if (!line)
	{
		free(save[fd]);
		save[fd] = NULL;
		return (NULL);
	}
	save[fd] = trim_save(save[fd]);
	return (line);
}
