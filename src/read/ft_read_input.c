/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 11:52:20 by mosantos          #+#    #+#             */
/*   Updated: 2025/10/29 11:52:24 by mosantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/shell.h"

int ft_read_command(t_shell *shell)
{
    shell->line = readline("minishell->mucuashell> ");
    if (shell->line == NULL)
        return (false);
    if (shell->line[0] == '\0')
    {
        free(shell->line);
        return (true);
    }
    if (shell->line)
        add_history(shell->line);
    return (true);
}