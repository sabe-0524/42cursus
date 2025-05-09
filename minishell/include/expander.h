/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:06:44 by sabe              #+#    #+#             */
/*   Updated: 2025/05/09 16:27:58 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include "../libft/libft.h"
# include <parser.h>
# include <tokenizer.h>

typedef enum e_env_state
{
	GENERAL,
	ENV,
}					t_env_state;

typedef enum e_quote_state
{
	GENERAL,
	QUOTE,
	DQUOTE,
}					t_quote_state;

typedef struct s_expander
{
	t_tree			*tree;
	t_node			*node;
	t_env_state		env_state;
	t_quote_state	quote_state;
	size_t			token_len;
	size_t			decrease;
	size_t			increase;
}					t_expander;

#endif
