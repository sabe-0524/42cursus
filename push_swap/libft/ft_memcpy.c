/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:37:41 by sabe              #+#    #+#             */
/*   Updated: 2024/04/22 12:13:50 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *buf1, const void *buf2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	if (buf1 == 0 && buf2 == 0)
		return (NULL);
	ptr1 = (unsigned char *)buf1;
	ptr2 = (unsigned char *)buf2;
	while (n-- > 0)
		*ptr1++ = *ptr2++;
	return (buf1);
}

// #include <stdio.h>
// int main(void)
// {
//     char    buf1[5] = "";
//     char    buf2[5] = "";
//     ft_memcpy(buf1, buf2, 0);
//     printf("%s", buf1);
//     return (0);
// }