/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:08:02 by mosantos          #+#    #+#             */
/*   Updated: 2025/10/16 15:08:05 by mosantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	ft_free_philo(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	if (philo)
	{
		while (i < data->total_philos)
		{
			pthread_mutex_destroy(&philo[i].meal_mutex);
			i++;
		}
		free(philo);
		philo = NULL;
	}
}

void	ft_free_all(t_data *data, t_philo *philo)
{
	int	i;

	if (data->forks)
	{
		i = 0;
		while (i < data->total_philos)
		{
			pthread_mutex_destroy(&data->forks[i]);
			i++;
		}
		free(data->forks);
		data->forks = NULL;
	}
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->stop_mutex);
	ft_free_philo(data, philo);
}

void	ft_cleanup_threads(t_data *data, t_philo *philo, int created)
{
	while (--created >= 0)
		pthread_join(philo[created].thread, NULL);
	ft_free_all(data, philo);
}