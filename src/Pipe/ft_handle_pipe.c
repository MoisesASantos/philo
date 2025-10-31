/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_pipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 11:38:06 by mosantos          #+#    #+#             */
/*   Updated: 2025/10/31 11:38:12 by mosantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void    writestr(int fd, char *str)
{
    write(fd, str, strlen(str));
}

int  main(int argc, char ***argv)
{
    int pipefd[2];

     | 
     
    pid_t   pid;
    char    buffer;

    if (pipe(pipefd) == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        close(pipefd[1]);
        writestr(STDOUT_FILENO, "Child: What is the secret in this pipe?\n");
        writestr(STDOUT_FILENO, "Child: \"");
        while (read(pipefd[0], &buffer, 1) > 0)
        {
            write(STDOUT_FILENO, &buffer, 1);
        }
        writestr(STDOUT_FILENO, "\"\n");
		writestr(STDOUT_FILENO, "Child: Wow! I must go see my father.\n");
        close(pipefd[0]);
        exit(0);
    }
    else
    {
        close(pipefd[0]);
        writestr(STDOUT_FILENO, "Parent: I'm writing a secret in this pipe...\n");
		writestr(pipefd[1], "\e[33mI am your father mwahahaha!\e[0m");
        close(pipefd[1]);
        wait(NULL);
		writestr(STDOUT_FILENO, "Parent: Hello child!\n");
		exit(0);
    }
}