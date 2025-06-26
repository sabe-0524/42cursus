/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 19:25:43 by sabe              #+#    #+#             */
/*   Updated: 2025/06/26 21:29:35 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <expander.h>

static void	process_general_state(t_token *token, t_expander *ex)
{
	if (ex_quote(token, ex))
		return ;
	if (ex_dquote(token, ex))
		return ;
	if (ex_dollar(token, ex))
		return ;
	ex->line_i++;
}

static void	process_in_quote_state(t_token *token, t_expander *ex)
{
	if (ex_quote_in_quote(token, ex))
		return ;
	ex->line_i++;
}

static void	process_in_dquote_state(t_token *token, t_expander *ex)
{
	if (ex_dollar(token, ex))
		return ;
	if (ex_dquote_in_dquote(token, ex))
		return ;
	ex->line_i++;
}

void	expand_token(t_token *token, t_env *env)
{
	t_expander	*ex;

	ex = init_expander(env);
	while (token->content[ex->line_i])
	{
		if (ex->quote_state == STATE_GENERAL)
			process_general_state(token, ex);
		else if (ex->quote_state == STATE_IN_QUOTE)
			process_in_quote_state(token, ex);
		else
			process_in_dquote_state(token, ex);
	}
	add_command(token, ex);
	change_content(token, ex);
	free_expander(ex);
}
