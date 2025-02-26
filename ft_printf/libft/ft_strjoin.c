/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:43:04 by sabe              #+#    #+#             */
/*   Updated: 2024/04/29 21:17:49 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy_in_strjoin(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (*(src + i) != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcat_in_strjoin(char *dest, const char *src)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(dest);
	while (src[i] != '\0')
	{
		dest[len + i] = src[i];
		i++;
	}
	dest[len + i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*ans;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	ans = malloc(sizeof(char) * (len + 1));
	if (!ans)
		return (NULL);
	ft_strcpy_in_strjoin(ans, s1);
	ft_strcat_in_strjoin(ans, s2);
	return (ans);
}

// #include <stdio.h>
// int main(void)
// {
//     char *ans;
//     char s1[] = "abcd";
//     char s2[] = "efg";
//     ans = ft_strjoin(s1, s2);
//     printf("%s\n", ans);
//     free(ans);
//     return (0);
// }

// while (s1[j] != 0)
// {
// 	ans[i++] = s1[j];
// 	j++;
// }
// j = 0;
// while (s2[j] != 0)
// {
// 	ans[i++] = s2[j];
// 	j++;
// }
// ans[i] = 0;