/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 17:03:00 by sabe              #+#    #+#             */
/*   Updated: 2025/04/28 23:34:00 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	test_print(t_token *token)
{
	while (token)
	{
		printf("token: %s\n", token->content);
		token = token->next;
	}
}

int	main(void)
{
	char	*line;
    t_tokenizer *token;

	while ((line = readline("minishell$ ")) != NULL)
	{
		if (*line)
		{
			add_history(line);
		}
		token = tokenizer(line);
		test_print(token->head);
		all_free_tokenizer(token);
	}
	return (0);
}
