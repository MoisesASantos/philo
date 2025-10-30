/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jda-cruz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:18:22 by jda-cruz          #+#    #+#             */
/*   Updated: 2025/07/11 23:02:13 by jda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_putnbr(int n)
{
	int	result;

	result = 0;
	if (n == -2147483648)
	{
		return (write(1, "-2147483648", 11));
	}
	if (n < 0)
	{
		result += ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		result += ft_putnbr(n / 10);
	result += ft_putchar(n % 10 + '0');
	return (result);
}
