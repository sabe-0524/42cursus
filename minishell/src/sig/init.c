/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 19:17:49 by sabe              #+#    #+#             */
/*   Updated: 2025/05/17 21:13:03 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minisig.h>
#include <signal.h>

void	normal_c(int signo)
{
	(void)signo;
    write (1, "\n", 1);
    rl_on_new_line();
    rl_replace_line("", 0);
    rl_redisplay();
}

void	init_signal(void)
{
	struct sigaction	sa;

    ft_memset(&sa, 0, sizeof(sa));
	sa.sa_handler = normal_c;
	sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;
	if (sigaction(SIGINT, &sa, NULL) == -1)
	{
		perror("sigaction");
		exit(EXIT_FAILURE);
	}
    sa.sa_handler = SIG_IGN;
    sa.sa_flags   = 0;
    if (sigaction(SIGQUIT, &sa, NULL) == -1) {
        perror("sigaction(SIGQUIT)");
        exit(EXIT_FAILURE);
    }
}
