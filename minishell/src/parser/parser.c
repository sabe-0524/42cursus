/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:48:20 by sabe              #+#    #+#             */
/*   Updated: 2025/05/31 19:00:06 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

t_parser	*parser(t_tokenizer *tk)
{
	t_parser	*ps;

	ps = init_parser(tk);
	recur_pipe(ps->tree->head);
	add_flag(ps->tree);
	return (ps);
}
