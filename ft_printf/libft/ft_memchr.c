/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:59:45 by sabe              #+#    #+#             */
/*   Updated: 2024/04/22 12:13:49 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *buf, int ch, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)buf;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)ch)
			return ((void *)(buf + i));
		i++;
	}
	return (NULL);
}
