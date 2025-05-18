/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minisig.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 19:18:00 by sabe              #+#    #+#             */
/*   Updated: 2025/05/18 16:01:52 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISIG_H
# define MINISIG_H
# define _POSIX_C_SOURCE 200809L

# include <minishell.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>

void	init_signal(void);
void	parent_signal(void);
void	child_signal(void);
void	heredoc_signal(void);

#endif
