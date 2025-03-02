/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:43:00 by sabe              #+#    #+#             */
/*   Updated: 2025/02/19 16:10:33 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_min(size_t len1, size_t len2)
{
	if ((int)len2 < 0)
		return (0);
	else if (len1 > len2)
		return (len2);
	else
		return (len1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	min_len;
	char	*ptr;
	size_t	count;

	count = 0;
	min_len = ft_min(len, ft_strlen(s) - start);
	ptr = (char *)malloc(sizeof(char) * (min_len + 1));
	if (!ptr)
		return (NULL);
	while (count < min_len)
	{
		ptr[count] = s[start + count];
		count++;
	}
	ptr[count] = '\0';
	return (ptr);
}
