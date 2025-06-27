/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 21:30:41 by sabe              #+#    #+#             */
/*   Updated: 2025/06/27 16:36:09 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>
#include <expander.h>

static void	add_heredoc_command(char *line, t_expander *ex)
{
	t_command	*new;

	new = make_heredoc_command(line, ex);
	if (!new)
	{
		exit(1);
	}
	ft_command_add_back(&ex->command, new);
}

static bool	heredoc_dollar(char *line, t_expander *ex)
{
	char	*key;

	if (line[ex->line_i] != '$' || !(is_separator(line[ex->line_i + 1])
			|| line[ex->line_i + 1] == '?'))
		return (false);
	add_heredoc_command(line, ex);
	ex->line_i++;
	ex->start_i++;
	if (line[ex->line_i] == '?')
		ex->line_i++;
	else
	{
		while (is_separator(line[ex->line_i]))
			ex->line_i++;
	}
	key = ft_substr(line, (unsigned int)ex->start_i, (size_t)(ex->line_i
				- ex->start_i));
	ex->start_i = ex->line_i;
	add_env(key, ex);
	free(key);
	return (true);
}

static char	*build_heredoc_content(t_expander *ex)
{
	size_t		sum;
	t_command	*tmp;
	char		*new;

	sum = total_len(ex->command);
	tmp = ex->command;
	new = ft_calloc(sum + 1, 1);
	if (!new)
		exit(1);
	while (tmp)
	{
		ft_strlcat(new, tmp->content, sum + 1);
		tmp = tmp->next;
	}
	return (new);
}

static void	process_general_state(char *line, t_expander *ex)
{
	if (heredoc_dollar(line, ex))
		return ;
	ex->line_i++;
}

void	put_heredoc(char *line, int fd, bool is_quote, t_env *env)
{
	t_expander	*ex;

	if (is_quote == true)
	{
		ft_putendl_fd(line, fd);
		return ;
	}
	ex = init_expander(env);
	while (line[ex->line_i])
	{
		process_general_state(line, ex);
	}
	add_heredoc_command(line, ex);
	free(line);
	line = build_heredoc_content(ex);
	ft_putendl_fd(line, fd);
	free(line);
	free_expander(ex);
}
