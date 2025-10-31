/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 22:58:58 by mosantos          #+#    #+#             */
/*   Updated: 2025/07/03 23:05:53 by mosantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_handle_pointer(void *ptr, int fd)
{
	if (ptr == NULL)
		return (write(fd, "(nil)", 5));
	write(fd, "0x", 2);
	return (ft_putnbr_base_fd((unsigned long)ptr,
			"0123456789abcdef", 16, fd) + 2);
}
