/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:56:40 by sabe              #+#    #+#             */
/*   Updated: 2024/04/22 12:14:33 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s) + 1;
	s += len - 1;
	while (len > 0)
	{
		if (*s == (char)c)
			return ((char *)s);
		len--;
		s--;
	}
	return (NULL);
}

// #include "libft.h"

// char *ft_strrchr(const char *s, int c)
// {
//     if (!s)
//         return (NULL);

//     size_t len = ft_strlen(s);
//     while (len > 0)
//     {
//         if (s[len - 1] == c)
//             return ((char *)&s[len - 1]);
//         len--;
//     }
//     return (NULL);
// }
