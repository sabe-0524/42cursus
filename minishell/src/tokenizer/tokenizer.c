/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 18:56:17 by sabe              #+#    #+#             */
/*   Updated: 2025/05/31 19:08:02 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokenizer.h>

static void	process_general_state(t_tokenizer *tk)
{
	if (skip_space(tk))
		return ;
	if (handle_quote_general(tk))
		return ;
	if (handle_operator(tk))
		return ;
	tk->line_i++;
}

static void	process_in_quote_state(t_tokenizer *tk)
{
	in_quote(tk);
}

static void	process_in_dquote_state(t_tokenizer *tk)
{
	in_dquote(tk);
}

static t_tokenizer	*finalize_tokenizer(t_tokenizer *tk)
{
	if (tk->state == STATE_GENERAL)
	{
		add_token(tk);
		return (tk);
	}
	else
	{
		all_free_tokenizer(tk);
		ft_putendl_fd("syntax error", 2);
		return (NULL);
	}
}

t_tokenizer	*tokenizer(char *line)
{
	t_tokenizer	*tk;

	tk = init_tokenizer(line);
	while (tk->line[tk->line_i])
	{
		if (tk->state == STATE_GENERAL)
			process_general_state(tk);
		else if (tk->state == STATE_IN_QUOTE)
			process_in_quote_state(tk);
		else if (tk->state == STATE_IN_DQUOTE)
			process_in_dquote_state(tk);
	}
	return (finalize_tokenizer(tk));
}
