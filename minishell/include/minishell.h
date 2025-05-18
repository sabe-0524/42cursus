/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:59:39 by sabe              #+#    #+#             */
/*   Updated: 2025/05/18 18:20:35 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <env.h>
# include <exec.h>
# include <expander.h>
# include <minisig.h>
# include <parser.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>
# include <tokenizer.h>
# include <unistd.h>

extern volatile sig_atomic_t	g_signal;

bool							is_line(char *line);

#endif
