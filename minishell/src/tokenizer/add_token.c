/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 22:34:15 by sabe              #+#    #+#             */
/*   Updated: 2025/05/31 19:21:58 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokenizer.h>

void	make_token(t_tokenizer *tokenizer, t_token *token)
{
	int	i;

	i = 0;
	token->content = (char *)ft_calloc((tokenizer->line_i - tokenizer->start_i)
			+ 1, sizeof(char));
	if (!token->content)
	{
		exit(1);
	}
	while (tokenizer->start_i < tokenizer->line_i)
	{
		token->content[i] = tokenizer->line[tokenizer->start_i];
		i++;
		tokenizer->start_i++;
	}
	token->content[i] = '\0';
	token->type = GENERAL;
}

void	add_token(t_tokenizer *tokenizer)
{
	t_token	*token;

	if (tokenizer->line_i == tokenizer->start_i)
		return ;
	token = (t_token *)ft_calloc(1, sizeof(t_token));
	if (!token)
	{
		exit(1);
	}
	make_token(tokenizer, token);
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

void	make_token_op_single(t_tokenizer *tokenizer, t_token *token)
{
	int	j;

	j = 0;
	token->content = (char *)ft_calloc(2, sizeof(char));
	if (!token->content)
	{
		exit(1);
	}
	while (j < 1)
	{
		token->content[j] = tokenizer->line[tokenizer->line_i];
		j++;
		tokenizer->line_i++;
		tokenizer->start_i++;
	}
	if (token->content[0] == '|')
		token->type = PIPE;
	if (token->content[0] == '>')
		token->type = GREATER;
	if (token->content[0] == '<')
		token->type = LESSER;
}

void	make_token_op_double(t_tokenizer *tokenizer, t_token *token)
{
	int	j;

	j = 0;
	token->content = (char *)ft_calloc(3, sizeof(char));
	if (!token->content)
	{
		exit(1);
	}
	while (j < 2)
	{
		token->content[j] = tokenizer->line[tokenizer->line_i];
		j++;
		tokenizer->line_i++;
		tokenizer->start_i++;
	}
	if (token->content[0] == '>')
		token->type = R_GREATER;
	else
		token->type = R_LESSER;
}

void	add_token_operator(t_tokenizer *tokenizer)
{
	t_token	*token;

	token = (t_token *)ft_calloc(1, sizeof(t_token));
	if (!token)
	{
		exit(1);
	}
	if ((tokenizer->line[tokenizer->line_i] == '>'
			&& tokenizer->line[tokenizer->line_i + 1] == '>')
		|| (tokenizer->line[tokenizer->line_i] == '<'
			&& tokenizer->line[tokenizer->line_i + 1] == '<'))
		make_token_op_double(tokenizer, token);
	else
		make_token_op_single(tokenizer, token);
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
