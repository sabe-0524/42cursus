/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recur_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:00:04 by sabe              #+#    #+#             */
/*   Updated: 2025/05/01 22:23:22 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

void	add_node_redirect(t_node *node, t_token *token)
{
	t_node	*left;
	t_node	*right;
	t_token	*prev;
	t_token	*file;
	t_token	*after;

	left = ft_calloc(1, sizeof *left);
	right = ft_calloc(1, sizeof *right);
	prev = token->prev;
	file = token->next;
	after = file->next;
	prev->next = after;
	if (after)
		after->prev = prev;
	token->prev = NULL;
	token->next = NULL;
	file->prev = NULL;
	file->next = NULL;
	left->token = file;
	right->token = node->token;
	node->left = left;
	node->right = right;
	node->token = token;
}

void	recur_redirect(t_node *node)
{
	t_token	*token;
	int		flag;

	flag = 0;
	token = node->token;
	while (token)
	{
		if (token->type > PIPE)
		{
			add_node_redirect(node, token);
			flag = 1;
			break ;
		}
		token = token->next;
	}
	if (flag)
	{
		recur_redirect(node->left);
		recur_redirect(node->right);
	}
}
