/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:42:11 by sabe              #+#    #+#             */
/*   Updated: 2024/04/22 12:14:16 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	char	*ans;

	i = 0;
	ans = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!ans)
		return (NULL);
	while (str[i] != '\0')
	{
		ans[i] = str[i];
		i++;
	}
	ans[i] = '\0';
	return (ans);
}

// #include <stdio.h>
// int main(void)
// {
//     char    *str = "";
//     char    *ans = ft_strdup(str);
//     printf("%s", ans);
//     free(ans);
//     return (0);
// }