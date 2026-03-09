/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 00:00:00 by sabe              #+#    #+#             */
/*   Updated: 2026/03/10 00:00:00 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static size_t	copy_str(char *dst, const char *src, size_t start)
{
	size_t	i;

	i = 0;
	while (src && src[i])
	{
		dst[start + i] = src[i];
		i++;
	}
	return (start + i);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	if (!str)
		return (NULL);
	while (*str != 0)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (*str == (char)c)
		return ((char *)str);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	end;
	char	*joined;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	joined = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!joined)
		return (free(s1), NULL);
	end = copy_str(joined, s1, 0);
	end = copy_str(joined, s2, end);
	joined[end] = '\0';
	free(s1);
	return (joined);
}
