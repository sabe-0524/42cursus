/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:44:42 by sabe              #+#    #+#             */
/*   Updated: 2024/04/28 18:28:59 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (ft_strlen(src));
	while (i < (n - 1) && src[i] != '\0')
	{
		dest[i] = (char)src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}
