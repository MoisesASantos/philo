/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 10:14:00 by sgaspar           #+#    #+#             */
/*   Updated: 2025/10/24 10:14:00 by sgaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../../lib/libft/libft.h"
# include "./ft_handle_input.h"
# define SHELLNAME "mucua-shell->"

enum e_flag_type
{
	COMMAND,
	PIPE,
	REDIRECT
};

typedef	struct	s_no
{
	enum e_flag_type flag;
	char *str;
	struct s_no *left;
	struct s_no *right;
}	t_no;

typedef struct s_shell
{
	enum e_flag_type flag;
	int	is_run;
	char	*line;
	t_no	*root;
}	t_shell;

#endif
