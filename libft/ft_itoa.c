/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 10:54:43 by sabe              #+#    #+#             */
/*   Updated: 2024/04/22 12:13:37 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	else
		return (nb);
}

int	count_digit(int nb)
{
	int	count;

	count = 0;
	if (nb < 0)
		count++;
	while (nb >= 10 || nb <= -10)
	{
		nb /= 10;
		count++;
	}
	count++;
	return (count);
}

void	ft_reverse(char *str)
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

char	*ft_itoa(int n)
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
	if (n < 0)
	{
		ans[len] = '-';
		len--;
	}
	while (i <= len)
	{
		ans[i] = ft_abs(n % 10) + '0';
		n /= 10;
		i++;
	}
	ft_reverse(ans);
	return (ans);
}

// #include <stdio.h>

// int main(void)
// {
//   int n = 0;
//   char  *ans = ft_itoa(n);
//   printf("%s", ans);
//   free(ans);
//   return (0);
// }