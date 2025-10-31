/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 12:54:57 by mosantos          #+#    #+#             */
/*   Updated: 2025/10/29 12:57:19 by mosantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./include/shell.h"

int main(int argc, char **argv)
{
	t_shell *shell;

	shell = malloc(sizeof(t_shell));
	(void)argc;
	(void)argv;
	while (1)
	{
		if (!ft_read_command(shell))
			break ;
		if (ft_syntax_error(shell->line))
		{
			ft_putstr_fd("Erro De Syntax\n", 1);
			return (1);
		}
		ft_putstr_fd(shell->line, 1);
		printf("\n");
	}
	return (1);
}
