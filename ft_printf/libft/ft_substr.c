/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:47:20 by sabe              #+#    #+#             */
/*   Updated: 2024/04/28 16:32:19 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_min(size_t num1, size_t num2)
{
	if (num1 < num2)
		return (num1);
	else
		return (num2);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		num;
	char	*ans;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	num = ft_min(ft_strlen(s) - start, len);
	ans = malloc(sizeof(char) * (num + 1));
	if (!ans)
		return (NULL);
	while (s[start + i] != 0 && i < len)
	{
		ans[i] = s[start + i];
		i++;
	}
	ans[i] = 0;
	return (ans);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char *s = "hola";
// 	char *ans = ft_substr(s, (unsigned int)0, -1);
// 	printf("%s", ans);
// 	free(ans);
// 	return (0);
// }