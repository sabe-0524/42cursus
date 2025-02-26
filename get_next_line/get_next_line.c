/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 12:14:32 by sabe              #+#    #+#             */
/*   Updated: 2024/05/23 13:01:58 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	char	*ans;
	size_t	i;
	size_t	j;
	size_t	len2;

	if (!s1 && !s2)
		return (NULL);
	i = -1;
	j = -1;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ans = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!ans)
	{
		free(s1);
		return (NULL);
	}
	while (++i < len1)
		ans[i] = s1[i];
	while (++j < len2)
		ans[i + j] = s2[j];
	ans[i + j] = '\0';
	free(s1);
	return (ans);
}

char	*ft_get_line(char *save)
{
	int		i;
	int		j;
	char	*ans;

	i = 0;
	j = -1;
	if (!save)
		return (NULL);
	if (save[0] == '\0')
		return (NULL);
	while (save[i] != '\n' && save[i] != '\0')
		i++;
	if (save[i] == '\n')
		ans = malloc(sizeof(char) * (i + 2));
	else
		ans = malloc(sizeof(char) * (i + 1));
	if (!ans)
		return (NULL);
	while (++j < i)
		ans[j] = save[j];
	if (save[j] == '\n')
		ans[j++] = '\n';
	ans[j] = '\0';
	return (ans);
}

char	*ft_trim_line(char *save)
{
	int		start;
	int		i;
	char	*ans;

	start = 0;
	i = 0;
	if (!save)
		return (NULL);
	while (save[start] != '\n' && save[start] != '\0')
		start++;
	if (save[start] == '\0')
		return (trim_sub(save));
	start++;
	ans = malloc(sizeof(char) * (ft_strlen(save) - start + 1));
	if (!ans)
		return (free(save), NULL);
	while (save[start + i] != '\0')
	{
		ans[i] = save[start + i];
		i++;
	}
	ans[i] = '\0';
	free(save);
	return (ans);
}

char	*line_sub(char *line, char **save, int read_bytes, char *buf)
{
	line = ft_get_line(*save);
	if (read_bytes == 0)
	{
		free(*save);
		*save = NULL;
	}
	else
		*save = ft_trim_line(*save);
	free(buf);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;
	char		*buf;
	int			read_bytes;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= 2147483647)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (free(save), NULL);
	read_bytes = 1;
	if (save && ft_strchr(save, '\n'))
		return (line_sub(line, &save, read_bytes, buf));
	while (read_bytes > 0)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1)
			return (get_sub(&save, buf));
		buf[read_bytes] = '\0';
		save = ft_strjoin(save, buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (line_sub(line, &save, read_bytes, buf));
}

// int	main(void)
// {
// 	int		fd;
// 	char	*ans;

// 	fd = open("./test.txt", O_RDONLY);
// 	while ((ans = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", ans);
// 		free(ans);
// 	}
// 	close(fd);
// }

// __attribute__((destructor)) static void destructor()
// {
// 	system("leaks -q a.out");
// }
