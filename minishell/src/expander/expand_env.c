/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:08:29 by sabe              #+#    #+#             */
/*   Updated: 2025/05/09 16:10:54 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <expander.h>

bool	is_separator(char c)
{
	if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || ('1' <= c
			&& c <= '9') || c == '_')
		return (true);
	else
		return (false);
}

void expand_env(t_token *token)
{
	size_t token_len;

	token_len = ft_strlen(token->content);
}
