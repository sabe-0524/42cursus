/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:32:41 by sabe              #+#    #+#             */
/*   Updated: 2024/05/05 10:14:52 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_d(va_list ap)
{
	int		num;
	char	*ans;
	int		i;

	num = va_arg(ap, int);
	ans = ft_itoa(num);
	i = 0;
	while (ans[i] != '\0')
	{
		if (write(1, &ans[i], 1) == -1)
			return (-1);
		i++;
	}
	free(ans);
	return (i);
}
