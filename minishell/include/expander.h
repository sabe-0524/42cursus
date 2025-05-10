/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:06:44 by sabe              #+#    #+#             */
/*   Updated: 2025/05/10 14:08:01 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include "../libft/libft.h"
# include <parser.h>
# include <tokenizer.h>

typedef struct s_command
{
	char				*content;
	bool				is_env;
	struct s_command	*next;
}						t_command;

typedef struct s_expander
{
	t_token_state		quote_state;
	int					start_i;
	int					line_i;
	t_command			*command;
}						t_expander;

t_expander				*init_expander(void);
void					add_env(char *key, t_expander *ex);
void					add_command(t_token *token, t_expander *ex);
bool					ex_dollar(t_token *token, t_expander *ex);
bool					ex_quote(t_token *token, t_expander *ex);
bool					ex_dquote(t_token *token, t_expander *ex);
bool					ex_quote_in_quote(t_token *token, t_expander *ex);
bool					ex_dquote_in_dquote(t_token *token, t_expander *ex);
void					expand_word(t_node *node);
void					expander(t_tree *tree);
t_expander				*init_expander(void);
void					change_content(t_token *token, t_expander *ex);
void					free_expander(t_expander *ex);

#endif
