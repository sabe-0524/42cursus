/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:36:33 by sabe              #+#    #+#             */
/*   Updated: 2025/05/09 16:26:28 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <expander.h>

void expand_token(t_token *token, t_expander *ex)
{
	expand_env(token, ex);
	expand_quote(token, ex);
}

void expand_word(t_node *node, t_expander *ex)
{
	t_token *token;

	token = node->token;
	while (token)
	{
		expand_token(token, ex);
		token = token->next;
	}
}
