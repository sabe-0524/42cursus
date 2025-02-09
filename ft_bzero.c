/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:51:43 by sabe              #+#    #+#             */
/*   Updated: 2025/02/09 16:12:20 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

// #include <stdio.h>
// #include <string.h>

// #define BUF_SIZE 16

// int	main(void)
// {
// 	char	buf1[BUF_SIZE];

// 	// 変数定義
// 	// 変数初期化
// 	ft_memset(buf1, '\0', BUF_SIZE);
// 	// 配列の内容を表示
// 	printf("初期化後の配列の要素を表示。\n");
// 	printf("buf1:%s\n", buf1);
// 	// メモリ領域を特定の文字で埋める
// 	ft_bzero(buf1, 4); // buf1の最初の4バイトをaにする
// 	// 配列の内容を表示
// 	printf("配列の要素を表示。\n");
// 	printf("buf1:%s\n", buf1);
// 	return (0);
// }
