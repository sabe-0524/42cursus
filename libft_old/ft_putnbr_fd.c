/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:55:36 by sabe              #+#    #+#             */
/*   Updated: 2024/04/22 12:14:12 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int ft_abs(int nb)
// {
//   if (nb < 0)
//     return (-nb);
//   else
//     return (nb);
// }

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n < 0)
		write(fd, "-", 1);
	if (n <= -10 || n >= 10)
	{
		ft_putnbr_fd(ft_abs(n / 10), fd);
		c = ft_abs(n % 10) + '0';
		write(fd, &c, 1);
	}
	else
	{
		c = ft_abs(n % 10) + '0';
		write(fd, &c, 1);
	}
}

// int main(void)
// {
//   int n = -123;
//   ft_putnbr_fd(n);
//   return (0);
// }