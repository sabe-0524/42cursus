/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 15:39:04 by sabe              #+#    #+#             */
/*   Updated: 2025/05/21 16:06:30 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minisig.h>

int	event_hook(void)
{
	return (0);
}


void	heredoc_c(int signo)
{
	(void)signo;
	write(1, "\n", 1);
	g_signal = 1;
	rl_done = 1;
}

void	heredoc_signal(void)
{
	struct sigaction	sa;

	rl_event_hook = event_hook;
	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_handler = heredoc_c;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (sigaction(SIGINT, &sa, NULL) == -1)
	{
		perror("sigaction");
		exit(EXIT_FAILURE);
	}
}
