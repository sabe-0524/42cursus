/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:50:40 by sabe              #+#    #+#             */
/*   Updated: 2024/04/22 12:14:32 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_strnstr(const char *str, const char *to_find, size_t n)
// {
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	j = 0;
// 	if (str == NULL && n == 0)
// 		return (NULL);
// 	if (str[i] == 0 && to_find[i] == 0 && n == 0)
// 		return ("");
// 	if (str == NULL && to_find == NULL)
// 		return ((char *)str);
// 	while (str[i] != '\0' && i + ft_strlen(to_find) <= n)
// 	{
// 		j = 0;
// 		while (str[i + j] == to_find[j] && str[i + j] != '\0' && i + j < n)
// 			j++;
// 		if (to_find[j] == '\0')
// 			return ((char *)(str + i));
// 		i++;
// 	}
// 	return (NULL);
// }

// #include "libft.h"

// char *ft_strnstr(const char *str, const char *to_find, size_t n)
// {
//     size_t i;
//     size_t j;

//     if (!str || !to_find)
//         return (NULL);

//     i = 0;
//     while (str[i] != '\0' && i < n)
//     {
//         j = 0;
//         while (to_find[j] != '\0' && str[i + j] == to_find[j] && (i + j) < n)
//             j++;
//         if (to_find[j] == '\0')
//             return ((char *)&str[i]);
//         i++;
//     }
//     return (NULL);
// }

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (str == NULL && n == 0)
		return ((char *)str);
	if (str[i] == '\0' && to_find[i] == '\0')
		return ((char *)str);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == to_find[j] && str[i + j] != '\0' && (i + j) < n)
			j++;
		if (to_find[j] == '\0')
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	char	*str = NULL;
// 	char	*to_find = "";
// 	char	*ans = ft_strnstr(str, to_find, 0);
// 	char	*ans2 = strnstr(str, to_find, 0);
// 	printf("%s\n", ans);
// 	printf("%s\n", ans2);
// 	return (0);
// }