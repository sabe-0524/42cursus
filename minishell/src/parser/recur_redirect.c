/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recur_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 21:00:04 by sabe              #+#    #+#             */
/*   Updated: 2025/05/09 15:19:55 by sabe             ###   ########.fr       */
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

	prev = token->prev;
	file = token->next;
	after = NULL;
	left = NULL;
	right = NULL;
	if (file)
		after = file->next;
	if (prev)
		prev->next = after;
	if (after)
		after->prev = prev;
	token->prev = token->next = NULL;
	if (file)
	{
		file->prev = file->next = NULL;
		left = ft_calloc(1, sizeof *left);
		left->token = file;
	}
	if (prev)
	{
		right = ft_calloc(1, sizeof *right);
		right->token = node->token;
	}
	node->left = left;
	node->right = right;
	node->token = token;
}

void	recur_redirect(t_node *node)
{
	t_token	*token;
	int		flag;

	if (!node)
		return ;
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
