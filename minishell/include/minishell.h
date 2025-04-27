/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:59:39 by sabe              #+#    #+#             */
/*   Updated: 2025/04/27 18:58:59 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_token
{
	t_token *prev;
	t_token *next;
	char *content;
	
}			t_token;

typedef struct s_node
{
	t_node	*right;
	t_node	*left;
	char	**content;

}			t_node;

#endif
