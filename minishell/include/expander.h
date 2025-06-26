/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:06:44 by sabe              #+#    #+#             */
/*   Updated: 2025/06/26 21:58:45 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include "../libft/libft.h"
# include <env.h>
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
	t_env				*env;
}						t_expander;

void					add_env(char *key, t_expander *ex);
void					add_command(t_token *token, t_expander *ex);
bool					ex_dollar(t_token *token, t_expander *ex);
bool					ex_quote(t_token *token, t_expander *ex);
bool					ex_dquote(t_token *token, t_expander *ex);
bool					ex_quote_in_quote(t_token *token, t_expander *ex);
bool					ex_dquote_in_dquote(t_token *token, t_expander *ex);
void					expand_word(t_node *node, t_env *env);
void					expander(t_tree *tree, t_env *env);
t_expander				*init_expander(t_env *env);
void					change_content(t_token *token, t_expander *ex);
void					free_expander(t_expander *ex);
void					expand_token(t_token *token, t_env *env);
void					ft_command_add_back(t_command **command,
							t_command *new);
size_t					total_len(t_command *command);
bool					is_separator(char c);

#endif
