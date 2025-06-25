/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recur_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 19:32:46 by sabe              #+#    #+#             */
/*   Updated: 2025/06/25 19:34:34 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static void	detach_redirect_token(t_token *token, t_token **prev,
		t_token **file, t_token **after)
{
	*prev = token->prev;
	*file = token->next;
	*after = NULL;
	if (*file)
		*after = (*file)->next;
	if (*prev)
		(*prev)->next = *after;
	if (*after)
		(*after)->prev = *prev;
	token->prev = NULL;
	token->next = NULL;
}

static t_node	*create_left_node_for_file(t_token *file)
{
	t_node	*left;

	if (!file)
		return (NULL);
	file->prev = NULL;
	file->next = NULL;
	left = ft_calloc(1, sizeof(*left));
	if (!left)
		exit(1);
	left->token = file;
	return (left);
}

static t_node	*create_right_node_for_prev(t_token *prev, t_token *after,
		t_token *head)
{
	t_token	*right_head;
	t_node	*right;

	if (prev)
		right_head = head;
	else
		right_head = after;
	if (!right_head)
		return (NULL);
	right_head->prev = NULL;
	right = ft_calloc(1, sizeof(*right));
	if (!right)
		exit(1);
	right->token = right_head;
	return (right);
}

void	add_node_redirect(t_node *node, t_token *token)
{
	t_token	*head;
	t_token	*prev;
	t_token	*file;
	t_token	*after;

	head = node->token;
	detach_redirect_token(token, &prev, &file, &after);
	node->left = create_left_node_for_file(file);
	node->right = create_right_node_for_prev(prev, after, head);
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
