/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:39:52 by sabe              #+#    #+#             */
/*   Updated: 2024/05/05 15:53:53 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	count_words(char const *str, char c)
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	if (str[0] != c && str[0] != '\0')
		count++;
	while (str[0] != '\0' && str[i] != '\0')
	{
		if (str[i - 1] == c && str[i] != c)
			count++;
		i++;
	}
	return (count);
}

size_t	count_len(char const *str, char c, int i)
{
	size_t	count;

	count = 0;
	while (str[i] != '\0' && str[i] != c)
	{
		count++;
		i++;
	}
	return (count);
}

char	**free_all(char **array, int index)
{
	int	i;

	i = -1;
	while (++i < index)
		free(array[i]);
	free(array);
	return (NULL);
}

char	**ft_split(char const *str, char c)
{
	char	**array;
	size_t	i;
	int		index;

	i = 0;
	index = 0;
	if (!str)
		return (NULL);
	array = malloc(sizeof(char *) * (count_words(str, c) + 1));
	if (!array)
		return (NULL);
	while (str[i] != '\0' && index < count_words(str, c))
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		array[index] = malloc(sizeof(char) * (count_len(str, c, i) + 1));
		if (!array[index])
			return (free_all(array, index));
		ft_strlcpy(array[index], str + i, count_len(str, c, i) + 1);
		i += count_len(str, c, i);
		index++;
	}
	array[index] = NULL;
	return (array);
}

// int	main(void)
// {
// 	char	*str;
// 	char	**ans;

// 	str = "";
// 	ans = ft_split(str, ' ');
// 	printf("%s\n", ans[0]);
// 	free(ans[0]);
// 	free(ans);
// 	return (0);
// }

// __attribute__((destructor)) static void destructor()
// {
// 	system("leaks -q a.out");
// }