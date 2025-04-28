/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 23:17:37 by sabe              #+#    #+#             */
/*   Updated: 2025/04/28 23:35:59 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokenizer.h>

void	all_free_tokenizer(t_tokenizer *tokenizer)
{
	t_token	*tmp;
	t_token	*next;

	if (!tokenizer)
		return ;
	if (tokenizer->line)
		free(tokenizer->line);
	tmp = tokenizer->head;
	while (tmp)
	{
		next = tmp->next;
		if (tmp->content)
			free(tmp->content);
		free(tmp);
		tmp = next;
	}
	tokenizer->head = NULL;
	tokenizer->last = NULL;
	free(tokenizer);
}
