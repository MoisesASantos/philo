/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_threads.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:34:24 by mosantos          #+#    #+#             */
/*   Updated: 2025/10/17 11:34:27 by mosantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*ft_routine(void *arg)
{
	t_philo	*philo = (t_philo *)arg;

	if (philo->ID % 2 == 0)
		usleep(1000);
	while (ft_is_running(philo->data))
	{
		ft_take_forks(philo);
		if (!ft_is_running(philo->data))
			break;
		ft_eating(philo);
		if (!ft_is_running(philo->data))
			break;
		ft_realese_fork(philo);
		ft_sleep(philo);
		ft_thinking(philo);
	}
	return (NULL);
}

void	*ft_police(void *arg)
{
	t_philo	*philo;
	t_data	*data;
	int		i;

	philo = (t_philo *)arg;
	data = philo[0].data;

	while (ft_is_running(data))
	{
		i = 0;
		while (i < data->total_philos)
		{
			pthread_mutex_lock(&philo[i].meal_mutex);
			if (get_time() - philo[i].last_meal_time > data->time_to_die)
			{
				ft_print_status(&philo[i], "died");
				ft_stop_simulation(data);
				pthread_mutex_unlock(&philo[i].meal_mutex);
				return (NULL);
			}
			pthread_mutex_unlock(&philo[i].meal_mutex);
			i++;
		}
		usleep(500);
	}
	return (NULL);
}

int	ft_init_thread(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->total_philos)
	{
		if (pthread_create(&philo[i].thread, NULL, ft_routine, &philo[i]) != 0)
			return (ft_cleanup_threads(data, philo, i), 0);
		i++;
	}
	if (pthread_create(&data->monitor_thread, NULL, ft_police, philo) != 0)
    	return (ft_cleanup_threads(data, philo, data->total_philos), 0);
	return (1);
}