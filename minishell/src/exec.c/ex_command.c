/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:52:04 by sabe              #+#    #+#             */
/*   Updated: 2025/05/10 22:07:27 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

size_t	count_token(t_node *node)
{
	t_token	*tk;
	size_t	count;

	count = 0;
	tk = node->token;
	while (tk)
	{
		count++;
		tk = tk->next;
	}
	return (count);
}

char	**make_command(t_node *node)
{
	size_t	count;
	char	**command;
	size_t	i;

	i = 0;
	count = count_token(node);
	command = (char **)ft_calloc((count + 1), sizeof(char *));
	while (i < count)
	{
		command[i] = node->token->content;
		node->token = node->token->next;
	}
	command[i] = NULL;
	return (command);
}

char	*find_filepath(char *s)
{
	char	*path;
	char	**paths;
	char	*tmp;
	int		i;

	i = -1;
	paths = ft_split(getenv("PATH"), ':');
	while (paths[++i])
	{
		tmp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(tmp, s);
		free(tmp);
		if (access(path, X_OK) == 0)
		{
			all_free(paths);
			return (path);
		}
		free(path);
	}
	all_free(paths);
	ft_putendl_fd("command not found", 2);
	exit(127);
}

char	*make_filepath(char **command)
{
	char	*filepath;

	if (ft_strchr(command[0], '/'))
		filepath = ft_strdup(command[0]);
	else
		filepath = find_filepath(command[0]);
	return (filepath);
}

void	ex_command(t_node *node, t_executor *ex)
{
	if (node->is_first)
		ex_command_first(node, ex);
	else if (node->is_last)
		ex_command_last(node, ex);
	else
		ex_command_middle(node, ex);
}
