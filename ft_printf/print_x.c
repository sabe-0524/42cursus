/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 19:58:42 by sabe              #+#    #+#             */
/*   Updated: 2024/05/05 10:16:10 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int	print_x_sub(unsigned int nbr, char *base)
// {
// 	int	count;

// 	count = 0;
// 	if (nbr >= 16)
// 	{
// 		print_x_sub(nbr / 16, base);
// 		write(1, &base[nbr % 16], 1);
// 		count++;
// 	}
// 	else
// 		write(1, &base[nbr % 16], 1);
// 	count++;
// 	return (count);
// }

static int	count_digit(unsigned int nb)
{
	int	count;

	count = 0;
	while (nb >= 16)
	{
		nb /= 16;
		count++;
	}
	count++;
	return (count);
}

static void	ft_reverse(char *str)
{
	int		len;
	char	tmp;
	int		i;

	len = ft_strlen(str);
	i = 0;
	while (i < len / 2)
	{
		tmp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = tmp;
		i++;
	}
}

static char	*ft_itoa_x(unsigned int n, char *base)
{
	char	*ans;
	int		len;
	int		i;

	len = count_digit(n) - 1;
	i = 0;
	ans = malloc(sizeof(char) * (count_digit(n) + 1));
	if (!ans)
		return (NULL);
	ans[len + 1] = 0;
	while (i <= len)
	{
		ans[i] = base[n % 16];
		n /= 16;
		i++;
	}
	ft_reverse(ans);
	return (ans);
}

int	print_x(va_list ap)
{
	int				count;
	char			*base;
	unsigned int	nbr;
	char			*ans;
	int				i;

	count = 0;
	nbr = va_arg(ap, unsigned int);
	base = "0123456789abcdef";
	ans = ft_itoa_x(nbr, base);
	i = -1;
	while (ans[++i] != '\0')
	{
		if (write(1, &ans[i], 1) == -1)
			return (-1);
		count++;
	}
	free(ans);
	return (count);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%x\n", 2147483648);
// 	print_x(2147483648);
// 	return (0);
// }