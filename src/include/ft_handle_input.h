/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_input.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 11:54:18 by mosantos          #+#    #+#             */
/*   Updated: 2025/10/29 11:54:23 by mosantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HANDLE_INPUT
# define FT_HANDLE_INPUT

typedef struct s_shell t_shell;

bool    ft_unclosed_quote(char *str);
bool    ft_pipe_error(char *str);
bool	ft_redirect_error(char *str);
int     ft_skip_quote(char *str, int i);
int     ft_read_command(t_shell *shell);
bool    ft_invalid_operator(char *str);
bool	ft_parenthesis_error(char *str);
bool	ft_syntax_error(char *str);

#endif