/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:38:18 by abesouichir       #+#    #+#             */
/*   Updated: 2025/05/20 14:41:26 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

void all_free_executor(t_executor *ex)
{
    if (ex == NULL)
        return;
    if (ex->pipe_fd[0] >= 0)
        close(ex->pipe_fd[0]);
    if (ex->pipe_fd[1] >= 0)
        close(ex->pipe_fd[1]);
    if (ex->in_fd >= 0 && ex->in_fd != STDIN_FILENO)
        close(ex->in_fd);
    if (ex->out_fd >= 0 && ex->out_fd != STDOUT_FILENO)
        close(ex->out_fd);
    if (ex->save_in >= 0 && ex->save_in != STDIN_FILENO)
        close(ex->save_in);
    free(ex);
}