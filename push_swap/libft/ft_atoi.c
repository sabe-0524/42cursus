/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 21:20:14 by sabe              #+#    #+#             */
/*   Updated: 2024/04/22 13:38:38 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	ft_atoi_sub(int flag, long ans, const char *str, int i)
{
	if (flag == 1 && (ans > LONG_MAX / 10 || (ans == LONG_MAX / 10 && (str[i]
					- '0') > LONG_MAX % 10)))
		return (1);
	if (flag == -1 && (ans > -(LONG_MIN / 10) || (ans == -(LONG_MIN / 10)
				&& (str[i] - '0') > -(LONG_MIN % 10))))
		return (-1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		flag;
	long	ans;

	i = 0;
	flag = 1;
	ans = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			flag *= -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		if (ft_atoi_sub(flag, ans, str, i) == 1)
			return ((int)(LONG_MAX));
		if (ft_atoi_sub(flag, ans, str, i) == -1)
			return ((int)(LONG_MIN));
		ans = ans * 10 + (str[i++] - '0');
	}
	return (ans * flag);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <limits.h>

// int ft_atoi(const char *str)
// {
//     int result = 0;
//     int sign = 1;
//     int i = 0;

//     // 空白文字をスキップ
//     while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
//         i++;

//     // 符号をチェック
//     if (str[i] == '+' || str[i] == '-')
//     {
//         sign = (str[i] == '-') ? -1 : 1;
//         i++;
//     }

//     // 数字を変換
//     while (str[i] >= '0' && str[i] <= '9')
//     {
//         // オーバーフローチェック
//         if (result > INT_MAX / 10 || (result == INT_MAX / 10 && (str[i]
//         {
//             fprintf(stderr, "Error: Overflow\n");
//             exit(EXIT_FAILURE);
//         }

//         result = result * 10 + (str[i] - '0');
//         i++;
//     }

//     return (result * sign);
// }

// int main()
// {
//     char str[] = "12345";
//     int num = ft_atoi(str);
//     printf("Converted number: %d\n", num);

//     return (0);
// }

// #include <libc.h>
// int main(){
//     printf("%d\n", ft_atoi("-92233720368547758010"));
//     printf("%d\n", atoi("-92233720368547758010"));
//     return (0);
// }
