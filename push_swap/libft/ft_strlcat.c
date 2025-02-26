/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:43:09 by sabe              #+#    #+#             */
/*   Updated: 2024/04/22 12:14:25 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// size_t ft_strlcat(char *dest, const char *src, size_t size)
// {
//     size_t i;
//     size_t j;

//     j = ft_strlen(dest);
//     i = ft_strlen(dest) - 1;
//     if (j > size)
//         return (size + ft_strlen(src));
//     while (++i < size - 1 && *src != 0)
//     {
//         dest[i] = *src;
//         src++;
//     }
//     dest[i] = 0;
//     return (j + ft_strlen(src));
// }

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	if (dest == NULL && size == 0)
		return (ft_strlen(src));
	len = ft_strlen(dest);
	if (size <= len)
		return (size + ft_strlen(src));
	while ((i < size - len - 1) && src[i] != '\0')
	{
		dest[len + i] = src[i];
		i++;
	}
	dest[len + i] = '\0';
	return (len + ft_strlen(src));
}

// char	*ft_strncpy(char *dest, char *src, int n)
// {
// 	int	i;

// 	i = 0;
// 	while (i < n && src[i] != '\0')
// 	{
// 		dest[i] = src[i];
// 		i++;
// 	}
// 	while (i < n)
// 	{
// 		dest[i] = '\0';
// 		i++;
// 	}
// 	return (dest);
// }

// size_t ft_strlcat(char *dest, const char *src, size_t size)
// {
//     size_t dest_len = ft_strlen(dest);
//     size_t src_len = ft_strlen(src);
//     size_t total_len = dest_len + src_len;

//     if (size <= dest_len)
//         return (total_len); // dest のサイズが size 以下の場合は dest の長さと src の長さを返す

//     size_t copy_len = size - dest_len - 1; // コピーする文字列の最大長（null 終端文字を考慮するため
//     ft_strncpy(dest + dest_len, src, copy_len); // dest の末尾からコピーを開始
//     dest[dest_len + copy_len] = '\0'; // dest の末尾に null 終端文字を追加

//     return (total_len); // 結果の文字列の長さを返す
// }

// #include <stdio.h>
// #include <string.h>

// int main(void)
// {
//   char *dst1 = calloc(100, sizeof(char));
// 	char *dst2 = calloc(100, sizeof(char));
// 	char *src1 = calloc(100, sizeof(char));
// 	char *src2 = calloc(100, sizeof(char));
//   for (int i = 0; i < 99; i++)
// 	{
// 		src1[i] = i + 1;
// 		src2[i] = i + 1;
// 	}
// 	dst1 = NULL;
// 	dst2 = NULL;
//     printf("%lu\n", ft_strlcat(dst1, src1, 0));
//     // printf("%s\n", dst1);
// 		printf("%lu\n", strlcat(dst2, src2, 0));
// 		// printf("%s\n", dst2);
//     return (0);
// }