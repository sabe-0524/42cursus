/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:21:31 by sabe              #+#    #+#             */
/*   Updated: 2024/04/22 12:13:32 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int	ft_isalpha(int c)
// {
// 	if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))
// 		return (1);
// 	else
// 		return (0);
// }

// int	ft_isdigit(int c)
// {
// 	if ('0' <= c && c <= '9')
// 		return (1);
// 	else
// 		return (0);
// }

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	else
		return (0);
}

// #include <stdio.h>

// int main(void)
// {
//     int num = ft_isalnum('6');
//     printf("%d", num);
//     return (0);
// }