/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 13:12:10 by sabe              #+#    #+#             */
/*   Updated: 2025/05/22 20:47:09 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <expander.h>

t_command	*ft_commandlast(t_command *command)
{
	if (!command)
		return (NULL);
	while (command->next != NULL)
		command = command->next;
	return (command);
}

void	ft_command_add_back(t_command **command, t_command *new)
{
	t_command	*last;

	if (!command || !new)
		return ;
	if (*command == NULL)
	{
		*command = new;
		return ;
	}
	last = ft_commandlast(*command);
	last->next = new;
}

t_command	*make_command(t_token *token, t_expander *ex)
{
	t_command	*new;

	new = (t_command *)ft_calloc(1, sizeof(t_command));
	if (!new)
	{
		exit(1); // TODO
	}
	new->content = ft_substr(token->content, (unsigned int)ex->start_i,
			(size_t)(ex->line_i - ex->start_i));
	if (!new->content)
	{
		exit(1); // TODO
	}
	new->is_env = false;
	ex->start_i = ex->line_i;
	return (new);
}

void	add_env(char *key, t_expander *ex)
{
	char		*env;
	t_command	*new;

	env = my_getenv(key, ex->env);
	if (!env)
		return ;
	new = (t_command *)ft_calloc(1, sizeof(t_command));
	if (!new)
	{
		exit(1); // TODO
	}
	new->content = env;
	new->is_env = true;
	ft_command_add_back(&ex->command, new);
}

void	add_command(t_token *token, t_expander *ex)
{
	t_command	*new;

	new = make_command(token, ex);
	if (!new)
	{
		exit(1); // TODO
	}
	ft_command_add_back(&ex->command, new);
}
