/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recur_ex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 16:43:06 by sabe              #+#    #+#             */
/*   Updated: 2025/06/18 02:34:56 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exec.h>

// static void	do_pipe_exec(t_node *node, t_executor *ex)
// {
// 	int	pipefd[2];

// 	if (pipe(pipefd) < 0)
// 	{
// 		perror("pipe");
// 		exit(EXIT_FAILURE);
// 	}
// 	ex->out_fd = pipefd[1];
// 	recur_ex(node->left, ex);
// 	if (!ft_strcmp(my_getenv("?", ex->env), "130"))
// 	{
// 		if (pipefd[0] > STDERR_FILENO)
// 			close(pipefd[0]);
// 		if (pipefd[1] > STDERR_FILENO)
// 			close(pipefd[1]);
// 		return ;
// 	}
// 	if (pipefd[1] > STDERR_FILENO)
// 		close(pipefd[1]);
// 	ex->in_fd = pipefd[0];
// 	ex->out_fd = STDOUT_FILENO;
// 	recur_ex(node->right, ex);
// 	if (pipefd[0] > STDERR_FILENO)
// 		close(pipefd[0]);
// }

static void do_pipe_exec(t_node *node, t_executor *ex)
{
    int pipefd[2];
    int saved_in  = ex->in_fd;
    int saved_out = ex->out_fd;

    if (pipe(pipefd) < 0)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // 左側を fork して並行実行
    pid_t pid_left = fork();
    if (pid_left < 0)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (pid_left == 0)
    {
        // child: writer
        if (saved_in != STDIN_FILENO)
        {
            dup2(saved_in, STDIN_FILENO);
            close(saved_in);
        }
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[0]);
        close(pipefd[1]);
        recur_ex(node->left, ex);
        exit(EXIT_FAILURE);
    }

    // 親は書き込み端を閉じ
    close(pipefd[1]);

    // 右側は親プロセスで実行、in_fd を更新
    ex->in_fd  = pipefd[0];
    ex->out_fd = saved_out;
    recur_ex(node->right, ex);

    // 親は読み込み端を閉じ、in/out を復元
    close(pipefd[0]);
    ex->in_fd  = saved_in;
    ex->out_fd = saved_out;
}


static void	handle_pipe_node(t_node *node, t_executor *ex)
{
	ex->use_pipe = true;
	do_pipe_exec(node, ex);
}

static void	handle_redirect_node(t_node *node, t_executor *ex)
{
	int	exit_code;

	exit_code = ex_redirect(node, ex);
	my_setenv_row(ex->env, "?", ft_itoa(exit_code));
	if (exit_code == 0 && node->right)
		recur_ex(node->right, ex);
}

static void	handle_command_node(t_node *node, t_executor *ex)
{
	int	exit_code;

	exit_code = ex_command_first(node, ex);
	if (node->is_last)
		ex->last_pid = ex->pid;
	my_setenv_row(ex->env, "?", ft_itoa(exit_code));
}

void	recur_ex(t_node *node, t_executor *ex)
{
	if (ft_strlen(node->token->content) == 0)
		return ;
	else if (node->token->type == PIPE)
		handle_pipe_node(node, ex);
	else if (node->token->type > PIPE)
		handle_redirect_node(node, ex);
	else
		handle_command_node(node, ex);
}
