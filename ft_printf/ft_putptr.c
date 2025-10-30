/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jda-cruz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 15:01:48 by jda-cruz          #+#    #+#             */
/*   Updated: 2025/07/11 22:57:38 by jda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

// Função auxiliar para imprimir o número hexadecimal de um unsigned long
int	ft_putptr_hex(unsigned long n)
{
	int		count;
	char	*base;

	base = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += ft_putptr_hex(n / 16);
	count += ft_putchar(base[n % 16]);
	return (count);
}

int	ft_putptr(void *ptr)
{
	unsigned long		addr;
	int					count;

	if (!ptr)
		return (write(1, "(nil)", 5));
	count = 0;
	addr = (unsigned long)ptr;
	count += ft_putstr("0x");
	count += ft_putptr_hex(addr);
	return (count);
}
