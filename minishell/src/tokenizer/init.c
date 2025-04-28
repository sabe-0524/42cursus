/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:20:41 by sabe              #+#    #+#             */
/*   Updated: 2025/04/28 22:37:06 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokenizer.h>

t_tokenizer	*init_tokenizer(char *line)
{
	t_tokenizer	*tokenizer;

	tokenizer = (t_tokenizer *)ft_calloc(1, sizeof(t_tokenizer));
	if (!tokenizer)
	{
		exit(1); // TODO
	}
	tokenizer->line = line;
	return (tokenizer);
}
