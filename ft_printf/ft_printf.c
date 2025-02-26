/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:49:47 by sabe              #+#    #+#             */
/*   Updated: 2024/05/09 13:18:05 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_next_per(const char *str, int i)
{
	if (str[i + 1] == 'c' || str[i + 1] == 's' || str[i + 1] == 'p')
		return (1);
	else if (str[i + 1] == 'd' || str[i + 1] == 'i' || str[i + 1] == 'u')
		return (1);
	else if (str[i + 1] == 'x' || str[i + 1] == 'X' || str[i + 1] == '%')
		return (1);
	else if (str[i + 1] == '\0')
		return (0);
	return (-1);
}

int	print_per(const char *str, int i, va_list ap)
{
	if (str[i + 1] == 'c')
		return (print_c(ap));
	else if (str[i + 1] == 's')
		return (print_s(ap));
	else if (str[i + 1] == 'p')
		return (print_p(ap));
	else if (str[i + 1] == 'd')
		return (print_d(ap));
	else if (str[i + 1] == 'i')
		return (print_i(ap));
	else if (str[i + 1] == 'u')
		return (print_u(ap));
	else if (str[i + 1] == 'x')
		return (print_x(ap));
	else if (str[i + 1] == 'X')
		return (print_x_up(ap));
	else
	{
		write(1, "%", 1);
		return (1);
	}
}

int	printf_sub(const char *str, int *i, va_list ap)
{
	int	count;

	count = 0;
	while (check_next_per(str, *i) != 1 && check_next_per(str, *i) != 0)
		(*i)++;
	if (check_next_per(str, *i) == 0)
	{
		va_end(ap);
		return (0);
	}
	count = print_per(str, (*i)++, ap);
	if (count == -1)
		va_end(ap);
	(*i)++;
	return (count);
}

int	printf_sub_nonper(const char *str, int *i, va_list ap, int *count)
{
	if (write(1, &str[(*i)++], 1) == -1)
	{
		va_end(ap);
		return (-1);
	}
	(*count)++;
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		count;
	int		tmp;

	count = 0;
	i = 0;
	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (str[i] != '%')
		{
			if (printf_sub_nonper(str, &i, ap, &count) == -1)
				return (-1);
		}
		else
		{
			tmp = printf_sub(str, &i, ap);
			if (tmp == -1)
				return (-1);
			count += tmp;
		}
	}
	va_end(ap);
	return (count);
}

// #include <limits.h>

// int	main(void)
// {
// 	int	n;
// 	int	m;

// 	n = ft_printf("%%c\n", 1);
// 	m = printf("%%c\n", 1);
// 	printf("n = %d\n", n);
// 	printf("m = %d\n", m);
// 	return (0);
// }

// if (check_per(str, i) == 0)
// {
// 	va_end(ap);
// 	return (0);
// }
// else if (check_per(str, i) == 1)
// 	i += 2;
// else if (check_per(str, i) == -1)
// {
// 	count += print_per(str, i, ap);
// 	i += 2;
// }
// else if (check_per(str, i) == 2)
// {
// 	write(1, &str[i], 1);
// 	i++;
// 	count++;
// }

// 	while (check_next_per(str, i) != 1 && check_next_per(str, i) != 0)
// 		i++;
// 	if (check_next_per(str, i) == 0)
// 	{
// 		va_end(ap);
// 		return (count);
// 	}
// 	count += print_per(str, i++, ap);
// 	i++;
// }