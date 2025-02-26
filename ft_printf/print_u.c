/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:43:40 by sabe              #+#    #+#             */
/*   Updated: 2024/05/05 10:15:53 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// static int	count_digit_u(int nb)
// {
// 	int	count;

// 	count = 0;
// 	while (nb >= 10 || nb <= -10)
// 	{
// 		nb /= 10;
// 		count++;
// 	}
// 	count++;
// 	return (count);
// }

// static void	ft_reverse_u(char *str)
// {
// 	int		len;
// 	char	tmp;
// 	int		i;

// 	len = ft_strlen(str);
// 	i = 0;
// 	while (i < len / 2)
// 	{
// 		tmp = str[i];
// 		str[i] = str[len - i - 1];
// 		str[len - i - 1] = tmp;
// 		i++;
// 	}
// }

// static char	*ft_itoa_u(int n)
// {
// 	char	*ans;
// 	int		len;
// 	int		i;

// 	len = count_digit_u(n) - 1;
// 	i = 0;
// 	ans = malloc(sizeof(char) * (count_digit_u(n) + 1));
// 	if (!ans)
// 		return (NULL);
// 	ans[len + 1] = 0;
// 	while (i <= len)
// 	{
// 		ans[i] = n % 10 + '0';
// 		n /= 10;
// 		i++;
// 	}
// 	ft_reverse_u(ans);
// 	return (ans);
// }

// int	print_u(va_list ap)
// {
// 	unsigned int num;
// 	char *ans;
// 	int i;

// 	num = va_arg(ap, unsigned int);
// 	ans = ft_itoa_u(num);
// 	i = 0;
// 	while (ans[i] != '\0')
// 	{
// 		write(1, &ans[i], 1);
// 		i++;
// 	}
// 	return (i);
// }

// int	print_u_sub(unsigned int nbr, char *base)
// {
// 	int	count;

// 	count = 0;
// 	if (nbr >= 10)
// 	{
// 		print_u_sub(nbr / 10, base);
// 		write(1, &base[nbr % 10], 1);
// 		count++;
// 	}
// 	else
// 		write(1, &base[nbr % 10], 1);
// 	count++;
// 	return (count);
// }

static int	count_digit(unsigned int nb)
{
	int	count;

	count = 0;
	while (nb >= 10)
	{
		nb /= 10;
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

static char	*ft_itoa_u(unsigned int n)
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
		ans[i] = n % 10 + '0';
		n /= 10;
		i++;
	}
	ft_reverse(ans);
	return (ans);
}

int	print_u(va_list ap)
{
	int				count;
	char			*ans;
	unsigned int	nbr;
	int				i;

	count = 0;
	nbr = va_arg(ap, unsigned int);
	ans = ft_itoa_u(nbr);
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
