/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jda-cruz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 19:31:04 by jda-cruz          #+#    #+#             */
/*   Updated: 2025/07/11 21:38:53 by jda-cruz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_putnbr_unsigned(unsigned int n)
{
	int	result;

	result = 0;
	if (n >= 10)
	{
		result += ft_putnbr_unsigned(n / 10);
	}
	result += ft_putchar(n % 10 + '0');
	return (result);
}
