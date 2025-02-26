/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:46:01 by sabe              #+#    #+#             */
/*   Updated: 2024/04/23 11:14:00 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	trim_judge(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != 0)
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

int	trim_judge_all(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i] != 0)
	{
		j = 0;
		while (set[j] != 0)
		{
			if (s1[i] == set[j])
				break ;
			j++;
		}
		if (set[j] == 0)
			return (0);
		i++;
	}
	return (1);
}

int	trim_count(char const *s1, char const *set)
{
	int	len;
	int	i;
	int	len_sub;

	len = ft_strlen(s1);
	len_sub = ft_strlen(s1) - 1;
	if (len == 0)
		return (len);
	i = 0;
	if (trim_judge_all(s1, set))
		return (1);
	while (s1[i] != 0 && trim_judge(s1[i], set) == 1)
	{
		len--;
		i++;
	}
	while (len_sub >= 0 && trim_judge(s1[len_sub], set) == 1)
	{
		len--;
		len_sub--;
	}
	return (len);
}

int	trim_end_judge(char const *s1, char const *set)
{
	int	index;

	index = ft_strlen(s1) - 1;
	while (index >= 0 && trim_judge(s1[index], set) == 1)
		index--;
	return (index);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ans;
	int		i;
	int		j;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = 0;
	ans = malloc(sizeof(char) * (trim_count(s1, set) + 1));
	if (!ans)
		return (NULL);
	while (trim_judge(s1[i], set) == 1)
		i++;
	while (i <= trim_end_judge(s1, set))
		ans[j++] = s1[i++];
	ans[j] = 0;
	return (ans);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char *s1 = "";
// 	char *set = "";
// 	char *ans = ft_strtrim(s1, set);
// 	printf("%s", ans);
// 	free(ans);
// 	return (0);
// }