/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:36:33 by sabe              #+#    #+#             */
/*   Updated: 2025/05/31 19:30:13 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <expander.h>

void	free_token(t_token *token)
{
	if (token->content)
		free(token->content);
	free(token);
}

static void	remove_blank_token(t_node *node, t_token *tk)
{
	if (!tk->prev && tk->next)
	{
		node->token = tk->next;
		tk->next->prev = NULL;
		free_token(tk);
	}
	else if (tk->prev && !tk->next)
	{
		tk->prev->next = NULL;
		free_token(tk);
	}
	else if (tk->prev && tk->next)
	{
		tk->prev->next = tk->next;
		tk->next->prev = tk->prev;
		free_token(tk);
	}
}

void	cut_if_blank(t_node *node)
{
	t_token	*tk;
	t_token	*next_tk;

	tk = node->token;
	while (tk)
	{
		next_tk = tk->next;
		if (ft_strlen(tk->content) == 0 && tk->is_env)
			remove_blank_token(node, tk);
		tk = next_tk;
	}
}

void	expand_word(t_node *node, t_env *env)
{
	t_token	*token;

	token = node->token;
	while (token)
	{
		expand_token(token, env);
		token = token->next;
	}
	cut_if_blank(node);
}
