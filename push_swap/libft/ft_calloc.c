/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:20:19 by sabe              #+#    #+#             */
/*   Updated: 2024/04/22 12:13:30 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_size;
	void	*buf;

	total_size = count * size;
	if (size != 0 && (count >= SIZE_MAX / size || total_size >= SIZE_MAX))
		return (NULL);
	buf = malloc(sizeof(void) * (size * count));
	if (!buf)
		return (NULL);
	ft_bzero(buf, size * count);
	return (buf);
}

// #include <stdio.h>
// int main(void)
// {
//     char    *ans;

//     // ans = (char *)ft_calloc(1000000, 10000);
// //    ans = (char *)calloc(0,0);
//     ans = (char *)calloc(0,0);
//     printf("%s\n", ans);
//     free(ans);
//     return (0);
// }

// // __attribute__((destructor))
// // static void destructor() {
// //     system("leaks -q a.out");
// // }