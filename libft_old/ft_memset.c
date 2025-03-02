/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:39:08 by sabe              #+#    #+#             */
/*   Updated: 2024/04/22 12:14:09 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)buf;
	while (n > 0)
	{
		*ptr = c;
		ptr++;
		n--;
	}
	return (buf);
}

// #include <stdio.h>

// int main(void)
// {
//     char    s[] = "abcdefg";
//     ft_memset(s + 2, '1', 2);
//     printf("%s", s);
//     return (0);
// }