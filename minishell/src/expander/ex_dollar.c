/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_dollar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 12:47:13 by sabe              #+#    #+#             */
/*   Updated: 2025/05/31 18:56:02 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <expander.h>

bool	is_separator(char c)
{
	if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || ('0' <= c
			&& c <= '9') || c == '_')
		return (true);
	else
		return (false);
}

bool	ex_dollar(t_token *token, t_expander *ex)
{
	char	*key;

	if (token->content[ex->line_i] != '$'
		|| !(is_separator(token->content[ex->line_i + 1])
			|| token->content[ex->line_i + 1] == '?'))
		return (false);
	token->is_env = true;
	add_command(token, ex);
	ex->line_i++;
	ex->start_i++;
	if (token->content[ex->line_i] == '?')
		ex->line_i++;
	else
	{
		while (is_separator(token->content[ex->line_i]))
			ex->line_i++;
	}
	key = ft_substr(token->content, (unsigned int)ex->start_i,
			(size_t)(ex->line_i - ex->start_i));
	ex->start_i = ex->line_i;
	add_env(key, ex);
	return (true);
}
