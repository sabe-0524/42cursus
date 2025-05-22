/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:36:33 by sabe              #+#    #+#             */
/*   Updated: 2025/05/22 21:11:09 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <expander.h>

void	free_token(t_token *token)
{
	if (token->content)
		free(token->content);
	free(token);
}

void	cut_if_blank(t_node *node)
{
	t_token	*tk;
	t_token	*tmp;

	tk = node->token;
	while (tk)
	{
		tmp = tk->next;
		if (ft_strlen(tk->content) == 0 && tk->is_env)
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
				free(tk);
			}
		}
		tk = tmp;
	}
}

void	expand_token(t_token *token, t_env *env)
{
	t_expander	*ex;

	ex = init_expander(env);
	while (token->content[ex->line_i])
	{
		if (ex->quote_state == STATE_GENERAL)
		{
			if (ex_quote(token, ex))
				continue ;
			if (ex_dquote(token, ex))
				continue ;
			if (ex_dollar(token, ex))
				continue ;
			ex->line_i++;
		}
		else if (ex->quote_state == STATE_IN_QUOTE)
		{
			if (ex_quote_in_quote(token, ex))
				continue ;
			ex->line_i++;
		}
		else
		{
			if (ex_dollar(token, ex))
				continue ;
			if (ex_dquote_in_dquote(token, ex))
				continue ;
			ex->line_i++;
		}
	}
	add_command(token, ex);
	change_content(token, ex);
	free_expander(ex);
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
