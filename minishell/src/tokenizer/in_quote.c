/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_quote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:28:16 by sabe              #+#    #+#             */
/*   Updated: 2025/05/31 19:05:39 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokenizer.h>

void	in_quote(t_tokenizer *tk)
{
	if (tk->line[tk->line_i] == '\'')
		tk->state = STATE_GENERAL;
	tk->line_i++;
}

void	in_dquote(t_tokenizer *tk)
{
	if (tk->line[tk->line_i] == '\"')
		tk->state = STATE_GENERAL;
	tk->line_i++;
}
