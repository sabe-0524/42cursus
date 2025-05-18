/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parent.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabe <sabe@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 15:14:47 by sabe              #+#    #+#             */
/*   Updated: 2025/05/18 15:27:23 by sabe             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minisig.h>

void	parent_c(int signo)
{
	(void)signo;
    write (1, "\n", 1);
    rl_on_new_line();
    rl_replace_line("", 0);
}

void parent_signal(void)
{
	struct sigaction sa;

	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_handler = parent_c;
	sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;
	if (sigaction(SIGINT, &sa, NULL) == -1)
	{
		perror("sigaction");
		exit(EXIT_FAILURE);
	}
}
