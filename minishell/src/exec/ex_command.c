/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:52:04 by sabe              #+#    #+#             */
/*   Updated: 2025/06/09 19:58:07 by sabe             ###   ########.fr       */
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

char	**make_shellcommand(t_node *node)
{
	size_t	count;
	char	**command;
	size_t	i;
	t_node	*copy;

	i = 0;
	copy = node;
	count = count_token(copy);
	command = (char **)ft_calloc((count + 1), sizeof(char *));
	while (i < count)
	{
		command[i] = copy->token->content;
		copy->token = copy->token->next;
		i++;
	}
	command[i] = NULL;
	return (command);
}

char	*find_filepath(char *s, t_executor *ex)
{
	char	*path;
	char	**paths;
	char	*tmp;
	int		i;

	i = -1;
	paths = ft_split(my_getenv("PATH", ex->env), ':');
	if (!paths)
	{
		ft_putendl_fd("No such file or directory", STDERR_FILENO);
		exit(127);
	}
	while (paths[++i])
	{
		tmp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(tmp, s);
		free(tmp);
		if (access(path, X_OK) == 0)
		{
			all_free_paths(paths);
			return (path);
		}
		free(path);
	}
	all_free_paths(paths);
	ft_putendl_fd("command not found", 2);
	exit(127);
}

char	*make_filepath(char **command, t_executor *ex)
{
	char	*filepath;

	if (ft_strchr(command[0], '/'))
		filepath = ft_strdup(command[0]);
	else
		filepath = find_filepath(command[0], ex);
	return (filepath);
}
