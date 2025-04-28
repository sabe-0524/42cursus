/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 22:34:15 by sabe              #+#    #+#             */
/*   Updated: 2025/04/28 23:09:00 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokenizer.h>

char	*make_content(t_tokenizer *tokenizer)
{
	char	*content;
	int		i;

	i = 0;
	content = (char *)ft_calloc((tokenizer->line_i - tokenizer->start_i) + 1,
			sizeof(char));
	if (!content)
	{
		exit(1); // TODO
	}
	while (tokenizer->start_i < tokenizer->line_i)
	{
		content[i] = tokenizer->line[tokenizer->start_i];
		i++;
		tokenizer->start_i++;
	}
	content[i] = '\0';
	return (content);
}

void	add_token(t_tokenizer *tokenizer)
{
	t_token	*token;

	if (tokenizer->line_i == tokenizer->start_i)
		return ;
	token = (t_token *)ft_calloc(1, sizeof(t_token));
	if (!token)
	{
		exit(1); // TODO
	}
	token->content = make_content(tokenizer);
	if (tokenizer->head == NULL)
	{
		tokenizer->head = token;
		tokenizer->last = token;
	}
	else
	{
		tokenizer->last->next = token;
		token->prev = tokenizer->last;
		tokenizer->last = token;
	}
}

char	*make_content_op(t_tokenizer *tokenizer, int i)
{
	char	*content;
	int		j;

	j = 0;
	content = (char *)ft_calloc(i + 1, sizeof(char));
	if (!content)
	{
		exit(1); // TODO
	}
	while (j < i)
	{
		content[j] = tokenizer->line[tokenizer->line_i];
		j++;
		tokenizer->line_i++;
		tokenizer->start_i++;
	}
	return (content);
}

void	add_token_operator(t_tokenizer *tokenizer)
{
	t_token	*token;

	token = (t_token *)ft_calloc(1, sizeof(t_token));
	if (!token)
	{
		exit(1); // TODO
	}
	if ((tokenizer->line[tokenizer->line_i] == '>'
			&& tokenizer->line[tokenizer->line_i + 1] == '>')
		|| (tokenizer->line[tokenizer->line_i] == '<'
			&& tokenizer->line[tokenizer->line_i + 1] == '<'))
		token->content = make_content_op(tokenizer, 2);
	else
		token->content = make_content_op(tokenizer, 1);
	if (tokenizer->head == NULL)
	{
		tokenizer->head = token;
		tokenizer->last = token;
	}
	else
	{
		tokenizer->last->next = token;
		token->prev = tokenizer->last;
		tokenizer->last = token;
	}
}
