/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 20:29:08 by sabe              #+#    #+#             */
/*   Updated: 2024/05/05 10:19:09 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int	print_p_sub(unsigned int nbr, char *base)
// {
// 	int	count;

// 	count = 0;
// 	if (nbr >= 16)
// 	{
// 		print_p_sub(nbr / 16, base);
// 		write(1, &base[nbr % 16], 1);
// 		count++;
// 	}
// 	else
// 		write(1, &base[nbr % 16], 1);
// 	count++;
// 	return (count);
// }

// int	print_p(va_list ap)
// {
// 	int count;
// 	char *base;
// 	unsigned int nbr;

// 	nbr = va_arg(ap, unsigned int);
// 	base = "0123456789abcdef";
// 	write(1, "0x", 2);
// 	count = 2;
// 	count += print_p_sub(nbr, base);
// 	return (count);
// }

int	print_p_sub(uintptr_t ptr, char *base)
{
	int	count;

	count = 0;
	if (ptr >= 16)
	{
		count += print_p_sub(ptr / 16, base);
		write(1, &base[ptr % 16], 1);
	}
	else
		write(1, &base[ptr % 16], 1);
	return (++count);
}

int	print_p(va_list ap)
{
	int			count;
	char		*base;
	uintptr_t	ptr;
	int			tmp;

	ptr = va_arg(ap, uintptr_t);
	base = "0123456789abcdef";
	count = 0;
	if (write(1, "0x", 2) == -1)
		return (-1);
	count += 2;
	tmp = print_p_sub(ptr, base);
	if (tmp == -1)
		return (-1);
	count += tmp;
	return (count);
}
