/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_dollar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 12:47:13 by sabe              #+#    #+#             */
/*   Updated: 2025/05/18 17:19:55 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <expander.h>

bool	is_separator(char c, t_expander *ex)
{
	if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || ('1' <= c
			&& c <= '9') || c == '_' || (c == '?' && ex->start_i == ex->line_i))
		return (true);
	else
		return (false);
}

bool	ex_dollar(t_token *token, t_expander *ex)
{
	char	*key;

	if (token->content[ex->line_i] != '$')
		return (false);
	add_command(token, ex);
	ex->line_i++;
	ex->start_i++;
	while (is_separator(token->content[ex->line_i], ex))
		ex->line_i++;
	key = ft_substr(token->content, (unsigned int)ex->start_i,
			(size_t)(ex->line_i - ex->start_i));
	ex->start_i = ex->line_i;
	add_env(key, ex);
	return (true);
}
