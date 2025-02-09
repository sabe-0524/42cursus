/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 17:36:12 by sabe              #+#    #+#             */
/*   Updated: 2025/02/09 17:58:42 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	count;

	count = 0;
	dst_len = ft_strlen(dst);
	while (count < dstsize - dst_len - 1 && src[count] != '\0')
	{
		dst[dst_len + count] = src[count];
		count++;
	}
	dst[dst_len + count] = '\0';
	if (dst_len < dstsize)
		return (dst_len + ft_strlen(src));
	else
		return (dstsize + ft_strlen(src));
}

// #include <assert.h>
// #include <stdio.h>
// #include <bsd/string.h>

// /*
//  * 自作の ft_strlcat 関数のプロトタイプ
//  * ft_strlcat は以下の仕様とします:
//  *   - dst に src を連結する。dstsize が与えられ、最大で dstsize - 1 文字まで書き込み、
//  *     最後にヌル文字 ('\0') を付加する。
//  *   - 戻り値は、初期の dst の長さと src の長さの合計（＝試みた連結後の文字列長）を返す。
//  *   - もし dstsize が初期の dst の長さより小さい場合、戻り値は dstsize + strlen(src) となる。
//  */

// int	main(void)
// {
// 	char	buffer[50];
// 	size_t	ret;

// 	/* テストケース1: 通常の連結（十分なバッファ） */
// 	strcpy(buffer, "Hello");
// 	ret = ft_strlcat(buffer, " World", sizeof(buffer));
// 	printf("テスト1: buffer = \"%s\", 戻り値 = %zu\n", buffer, ret);
// 	// 期待: "Hello World" が作られる。戻り値は strlen("Hello") + strlen(" World")
// 	assert(strcmp(buffer, "Hello World") == 0);
// 	assert(ret == strlen("Hello") + strlen(" World"));
// 	/* テストケース2: バッファサイズが丁度足りる場合
// 		* "Hello" (5文字) + "World" (5文字) + '\0' の合計 11 バイト */
// 	strcpy(buffer, "Hello");
// 	ret = ft_strlcat(buffer, "World", 11);
// 	printf("テスト2: buffer = \"%s\", 戻り値 = %zu\n", buffer, ret);
// 	// 期待: "HelloWorld"、戻り値は 5 + 5 = 10
// 	assert(strcmp(buffer, "HelloWorld") == 0);
// 	assert(ret == strlen("Hello") + strlen("World"));
// 	/* テストケース3: バッファサイズ不足による切り詰め
// 		* buffer に "Hello" (5文字) が入っており、dstsize = 8 の場合、
// 		* 書き込み可能なスペースは 8 - 5 - 1 = 2 文字となるので、
// 		* src "World" から先頭 2 文字 ("Wo") が連結される */
// 	strcpy(buffer, "Hello");
// 	ret = ft_strlcat(buffer, "World", 8);
// 	printf("テスト3: buffer = \"%s\", 戻り値 = %zu\n", buffer, ret);
// 	// 期待: buffer には "HelloWo" が入っている（ヌル終端済み）。
// 	assert(strcmp(buffer, "HelloWo") == 0);
// 	// 戻り値は常に初期の dst の長さと src の長さの合計 = 5 + 5 = 10
// 	assert(ret == 10);
// 	/* テストケース4: dstsize が 0 の場合
// 		* 何も書き込まれず、戻り値は (dstsize < strlen(dst) のため)
// 		* dstsize + strlen(src) となる。ここでは dstsize = 0 かつ strlen("World") = 5 なので、
// 		* 戻り値は 5 となる。buffer の内容は変更されない（ただし、buffer は既に "Hello" が入っている） */
// 	strcpy(buffer, "Hello");
// 	ret = ft_strlcat(buffer, "World", 0);
// 	printf("テスト4: buffer = \"%s\", 戻り値 = %zu\n", buffer, ret);
// 	assert(ret == 0 + strlen("World"));
// 	/* テストケース5: dst が空文字の場合
// 		* 初期 dst の長さが 0 なので、src がそのままコピーされる */
// 	buffer[0] = '\0';
// 	ret = ft_strlcat(buffer, "Hello", sizeof(buffer));
// 	printf("テスト5: buffer = \"%s\", 戻り値 = %zu\n", buffer, ret);
// 	assert(strcmp(buffer, "Hello") == 0);
// 	assert(ret == 0 + strlen("Hello"));
// 	/* テストケース6: src が空文字の場合
// 		* dst はそのままで、戻り値は初期 dst の長さとなる */
// 	strcpy(buffer, "Hello");
// 	ret = ft_strlcat(buffer, "", sizeof(buffer));
// 	printf("テスト6: buffer = \"%s\", 戻り値 = %zu\n", buffer, ret);
// 	assert(strcmp(buffer, "Hello") == 0);
// 	assert(ret == strlen("Hello"));
// 	printf("すべてのテストをパスしました。\n");
// 	return (0);
// }
