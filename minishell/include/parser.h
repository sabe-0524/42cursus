/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:48:29 by sabe              #+#    #+#             */
/*   Updated: 2025/05/02 21:40:03 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <tokenizer.h>

typedef struct s_node
{
	struct s_node	*right;
	struct s_node	*left;
	t_token			*token;
}					t_node;

typedef struct s_tree
{
	t_node			*head;
}					t_tree;

typedef struct s_parser
{
	t_tree			*tree;
}					t_parser;

void				recur_redirect(t_node *node);
void				recur_pipe(t_node *node);
t_parser			*init_parser(t_tokenizer *tk);
t_parser			*parser(t_tokenizer *tk);
bool				is_error_ast(t_tree *tree);
void				all_free_parser(t_parser *ps);

#endif
