/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:00:45 by mosantos          #+#    #+#             */
/*   Updated: 2025/10/20 14:00:48 by mosantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_print_status(t_philo *philo, const char *str)
{
	size_t	time;

	pthread_mutex_lock(&philo->data->print_mutex);
	if (ft_is_running(philo->data))
	{
		time = get_time() - philo->data->start_time;
		printf("%zu %d %s\n", time, philo->ID, str);
	}
	pthread_mutex_unlock(&philo->data->print_mutex);
}

int	ft_is_running(t_data *data)
{
	int	running;

	pthread_mutex_lock(&data->stop_mutex);
	running = (data->stop == 0);
	pthread_mutex_unlock(&data->stop_mutex);
	return (running);
}

void	ft_stop_simulation(t_data *data)
{
	pthread_mutex_lock(&data->stop_mutex);
	data->stop = 1;
	pthread_mutex_unlock(&data->stop_mutex);
}