/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:00:13 by sabe              #+#    #+#             */
/*   Updated: 2025/05/21 15:34:02 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "../libft/libft.h"
# include <env.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef enum e_token_state
{
	STATE_GENERAL,
	STATE_IN_DQUOTE,
	STATE_IN_QUOTE,
}					t_token_state;

typedef enum e_token_type
{
	GENERAL,
	PIPE,
	LESSER,
	GREATER,
	R_LESSER,
	R_GREATER,
}					t_token_type;

typedef struct s_token
{
	struct s_token	*prev;
	struct s_token	*next;
	char			*content;
	t_token_type	type;
}					t_token;

typedef struct s_tokenizer
{
	t_token			*head;
	t_token			*last;
	size_t			line_i;
	size_t			start_i;
	t_token_state	state;
	char			*line;
}					t_tokenizer;

t_tokenizer			*init_tokenizer(char *line);
void				add_token(t_tokenizer *tokenizer);
bool				handle_operator(t_tokenizer *tokenizer);
bool				handle_quote_general(t_tokenizer *tokenizer);
bool				skip_space(t_tokenizer *tokenizer);
void				add_token_operator(t_tokenizer *tokenizer);
t_tokenizer			*tokenizer(char *line);
void				all_free_tokenizer(t_tokenizer *tokenizer);
void				in_quote(t_tokenizer *tk);
void				in_dquote(t_tokenizer *tk);
void				free_tokenizer(t_tokenizer *tk);

#endif
