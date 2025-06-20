/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recur_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 20:32:28 by sabe              #+#    #+#             */
/*   Updated: 2025/06/20 14:09:43 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static t_node	*build_left_node(t_token *head, t_token *prev)
{
	t_node	*left;

	if (!prev)
		return (NULL);
	prev->next = NULL;
	left = ft_calloc(1, sizeof(*left));
	if (!left)
		exit(1);
	left->token = head;
	return (left);
}

static t_node	*build_right_node(t_token *next)
{
	t_node	*right;

	if (!next)
		return (NULL);
	next->prev = NULL;
	right = ft_calloc(1, sizeof(*right));
	if (!right)
		exit(1);
	right->token = next;
	return (right);
}

void	add_node_pipe(t_node *node, t_token *token)
{
	t_token	*head;
	t_token	*prev;
	t_token	*next;

	head = node->token;
	prev = token->prev;
	next = token->next;
	node->left = build_left_node(head, prev);
	node->right = build_right_node(next);
	token->prev = NULL;
	token->next = NULL;
	node->token = token;
}

static t_token	*find_last_pipe(t_token *tok)
{
	t_token	*last;

	last = NULL;
	while (tok)
	{
		if (tok->type == PIPE)
			last = tok;
		tok = tok->next;
	}
	return (last);
}

void	recur_pipe(t_node *node)
{
	t_token	*pipe;

	if (!node)
		return ;
	pipe = find_last_pipe(node->token);
	if (pipe)
	{
		add_node_pipe(node, pipe);
		recur_pipe(node->left);
		recur_pipe(node->right);
	}
	recur_redirect(node);
}
