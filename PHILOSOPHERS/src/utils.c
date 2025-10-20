/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:56:42 by mosantos          #+#    #+#             */
/*   Updated: 2025/10/16 11:56:45 by mosantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"


static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	ft_putendl_fd(char *str, int fd)
{
	if (!str)
		return ;
	while (*str)
		write(fd, str++, 1);
	write(fd, "\n", 1);
}

static size_t	parse_digits(const char *nptr, int sign, int *error_flag)
{
	size_t	result;
	size_t	digit;

	result = 0;
	while (ft_isdigit(*nptr))
	{
		digit = *nptr - '0';
		if (sign == 1 && result > (INT_MAX - digit) / 10)
			return (*error_flag = 0, 0);
		if (sign == -1 && result > ((size_t)
				INT_MAX + 1 - digit) / 10)
			return (*error_flag = 0, 0);
		result = result * 10 + digit;
		nptr++;
	}
	return (result * sign);
}

size_t	ft_atoll(const char *nptr, int *error_flag)
{
	size_t	sign;

	sign = 1;
	if (!nptr)
	{
		ft_putendl_fd("Error", 2);
		exit(1);
	}
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	if (!ft_isdigit(*nptr))
		return (*error_flag = 0, 0);
	return (parse_digits(nptr, sign, error_flag));
}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_time();
	while ((get_time() - start) < milliseconds)
		usleep(500);
	return (0);
}