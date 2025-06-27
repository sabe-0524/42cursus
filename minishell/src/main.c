/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 17:03:00 by sabe              #+#    #+#             */
/*   Updated: 2025/06/27 14:43:56 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

volatile sig_atomic_t	g_signal;

static t_env	*setup_env(char **envp)
{
	t_env	*env;

	env = init_env(envp);
	my_setenv_row(env, "?", ft_itoa(EXIT_SUCCESS));
	return (env);
}

static void	process_command_line(char *line, t_env *env)
{
	t_tokenizer	*tk;
	t_parser	*ps;

	add_history(line);
	tk = tokenizer(line);
	if (!tk)
	{
		my_setenv_row(env, "?", ft_itoa(2));
		all_free_tokenizer(tk);
		return ;
	}
	ps = parser(tk);
	if (is_error_ast(ps->tree))
	{
		ft_putendl_fd("sysntax error", 2);
		free_for_next(ps, tk);
		my_setenv_row(env, "?", ft_itoa(2));
		return ;
	}
	expander(ps->tree, env);
	exec(ps->tree, env);
	free_for_next(ps, tk);
}

static void	shell_loop(t_env *env)
{
	char	*line;

	while (1)
	{
		init_signal();
		line = readline("minishell$ ");
		if (g_signal == 1)
		{
			my_setenv_row(env, "?", ft_itoa(130));
			g_signal = 0;
		}
		if (line == NULL)
			break ;
		init_signal();
		if (is_line(line))
			process_command_line(line, env);
		else
			free(line);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_env	*env;

	if (argc != 1 && argv[0])
		return (1);
	env = setup_env(envp);
	shell_loop(env);
	all_free_env(env);
	rl_clear_history();
	return (0);
}
