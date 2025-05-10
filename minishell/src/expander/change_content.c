/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_content.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 13:48:51 by sabe              #+#    #+#             */
/*   Updated: 2025/05/10 13:58:46 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <expander.h>

size_t	total_len(t_command *command)
{
	t_command	*tmp;
	size_t		sum;

	sum = 0;
	tmp = command;
	while (tmp)
	{
		sum += ft_strlen(tmp->content);
		tmp = tmp->next;
	}
	return (sum);
}

void	cat_content(t_token *token, t_expander *ex, size_t sum)
{
	t_command	*tmp;

	tmp = ex->command;
	while (tmp)
	{
		ft_strlcat(token->content, tmp->content, sum + 1);
		tmp = tmp->next;
	}
}

void	change_content(t_token *token, t_expander *ex)
{
	size_t	sum;

	sum = total_len(ex->command);
	if (token->content)
		free(token->content);
	token->content = (char *)ft_calloc((sum + 1), sizeof(char));
	cat_content(token, ex, sum);
}
