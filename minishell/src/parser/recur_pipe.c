/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recur_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 20:32:28 by sabe              #+#    #+#             */
/*   Updated: 2025/05/09 15:26:49 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

// void	add_node_pipe(t_node *node, t_token *token)
// {
// 	t_node	*left;
// 	t_node	*right;

// 	left = (t_node *)ft_calloc(1, sizeof(t_node));
// 	if (!left)
// 	{
// 		exit(1); // TODO
// 	}
// 	right = (t_node *)ft_calloc(1, sizeof(t_node));
// 	if (!right)
// 	{
// 		exit(1); // TODO
// 	}
// 	left->token = node->token;
// 	right->token = token->next;
// 	node->left = left;
// 	node->right = right;
// 	node->token = token;
// 	node->token->next = NULL;
//   if (node->right->token)
// 			node->right->token->prev = NULL;
//   if (node->token->prev)
// 			node->token->prev->next = NULL;
// 	node->token->prev = NULL;
// }

void	add_node_pipe(t_node *node, t_token *token)
{
	t_token	*head;
	t_token	*prev;
	t_token	*next;
	t_node	*left;
	t_node	*right;

	head = node->token;
	prev = token->prev;
	next = token->next;
	left = NULL;
	right = NULL;
	if (prev)
	{
		prev->next = NULL;
		left = ft_calloc(1, sizeof(*left));
		if (!left)
			exit(1);
		left->token = head;
	}
	if (next)
	{
		next->prev = NULL;
		right = ft_calloc(1, sizeof(*right));
		if (!right)
			exit(1);
		right->token = next;
	}
	node->left = left;
	node->right = right;
	token->prev = NULL;
	token->next = NULL;
	node->token = token;
}

void	recur_pipe(t_node *node)
{
	t_token	*token;
	int		flag;

	if (!node)
		return ;
	flag = 0;
	token = node->token;
	while (token)
	{
		if (token->type == PIPE)
		{
			add_node_pipe(node, token);
			flag = 1;
			break ;
		}
		token = token->next;
	}
	if (flag)
	{
		recur_pipe(node->left);
		recur_pipe(node->right);
	}
	recur_redirect(node);
}
