/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 20:20:50 by sabe              #+#    #+#             */
/*   Updated: 2025/05/31 19:00:39 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

t_parser	*init_parser(t_tokenizer *tk)
{
	t_parser	*ps;

	ps = (t_parser *)ft_calloc(1, sizeof(t_parser));
	if (!ps)
	{
		exit(1);
	}
	ps->tree = (t_tree *)ft_calloc(1, sizeof(t_tree));
	if (!ps->tree)
	{
		exit(1);
	}
	ps->tree->head = (t_node *)ft_calloc(1, sizeof(t_node));
	if (!ps->tree->head)
	{
		exit(1);
	}
	ps->tree->head->token = tk->head;
	return (ps);
}
