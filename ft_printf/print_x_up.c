/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x_up.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 20:27:38 by sabe              #+#    #+#             */
/*   Updated: 2024/05/07 12:04:50 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int	print_x_up_sub(unsigned int nbr, char *base)
// {
// 	int	count;

// 	count = 0;
// 	if (nbr >= 16)
// 	{
// 		print_x_up_sub(nbr / 16, base);
// 		write(1, &base[nbr % 16], 1);
// 		count++;
// 	}
// 	else
// 		write(1, &base[nbr % 16], 1);
// 	count++;
// 	return (count);
// }

// int	print_x_up(va_list ap)
// {
// 	int count;
// 	char *base;
// 	unsigned int nbr;

// 	nbr = va_arg(ap, unsigned int);
// 	base = "0123456789ABCDEF";
// 	count = print_x_up_sub(nbr, base);
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

static char	*ft_itoa_x_up(unsigned int n, char *base)
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

int	print_x_up(va_list ap)
{
	int				count;
	char			*base;
	unsigned int	nbr;
	char			*ans;
	int				i;

	count = 0;
	nbr = va_arg(ap, unsigned int);
	base = "0123456789ABCDEF";
	ans = ft_itoa_x_up(nbr, base);
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
