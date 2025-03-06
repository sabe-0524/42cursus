/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesouichirou <abesouichirou@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 16:36:31 by abesouichir       #+#    #+#             */
/*   Updated: 2025/03/06 22:42:05 by abesouichir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
extern char **environ;

void handle_first(char **argv, int *in_fd)
{
    char **command;
    char *filepath;
    int pipe_fd[2];

    if (pipe(pipe_fd) == -1)
    {
        //エラー処理
    }
    pid_t pid = fork();
    if (pid < 0)
    {
        //エラー処理
    }
    else if (pid == 0)
    {
        dup2(pipe_fd[1], STDOUT_FILENO);
        close(pipe_fd[0]);
        close(pipe_fd[1]);
        command = make_command(argv, 2);
        filepath = make_filepath(command);
        execve(filepath, command, environ);
        perror("execve");
        exit(EXIT_FAILURE);
    }
    else
    {
        close(pipe_fd[1]);
        *in_fd = pipe_fd[0];
    }
}

void handle_middle(char **argv, int *in_fd, int index)
{
    char **command;
    char *filepath;
    int pipe_fd[2];

    if (pipe(pipe_fd) == -1)
    {
        //エラー処理
    }
    pid_t pid = fork();
    if (pid < 0)
    {
        //エラー処理
    }
    else if (pid == 0)
    {
        if (*in_fd != STDIN_FILENO)
        {
            dup2(*in_fd, STDIN_FILENO);
            close(*in_fd);
        }
        dup2(pipe_fd[1], STDOUT_FILENO);
        close(pipe_fd[1]);
        close(pipe_fd[0]);
        command = make_command(argv, index);
        filepath = make_filepath(command);
        fprintf(stderr, "%s\n", filepath);
        execve(filepath, command, environ);
        perror("execve");
        exit(EXIT_FAILURE);
    }
    else
    {
        if (*in_fd != STDIN_FILENO)
            close(*in_fd);
        close(pipe_fd[1]);
        *in_fd = pipe_fd[0];
    }
    
}

void handle_last(int *in_fd, int outfile)
{
    char c;
    int count;

    pid_t pid = fork();
    if (pid < 0)
    {
        //エラー処理
    }
    else if (pid == 0)
    {
        if (*in_fd != STDIN_FILENO)
        {
            dup2(*in_fd, STDIN_FILENO);
            close(*in_fd);
        }
        while ((count = read(STDIN_FILENO, &c, 1)) > 0)
            write(outfile, &c, 1);
        if (count < 0)
        {
            //エラー処理
        }
        exit(0);
    }
    else
    {
    }
}

void handle_command(int argc, char **argv, int outfile)
{
    int index;
    int in_fd;
    
    index = 3;
    handle_first(argv ,&in_fd);
    while (index < argc - 1)
    {
        handle_middle(argv, &in_fd, index);
        index++;
    }
    handle_last(&in_fd, outfile);
    while (wait(NULL) > 0)
        ;
}