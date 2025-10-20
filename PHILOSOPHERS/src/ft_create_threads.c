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
		{
			ft_realese_fork(philo);
			break;
		}
		ft_realese_fork(philo);
		ft_sleep(philo);
		ft_thinking(philo);
	}
	return (NULL);
}

static int	check_philosopher_death(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->total_philos)
	{
		pthread_mutex_lock(&philo[i].meal_mutex);
		if (get_time() - philo[i].last_meal_time > data->time_to_die)
		{
			ft_print_status(&philo[i], "died");
			ft_stop_simulation(data);
			pthread_mutex_unlock(&philo[i].meal_mutex);
			return (1);
		}
		pthread_mutex_unlock(&philo[i].meal_mutex);
		i++;
	}
	return (0);
}

static int	check_all_ate_enough(t_philo *philo, t_data *data)
{
	int	i;
	int	finished_eating;

	if (data->total_meal == -1)
		return (0);
	
	i = 0;
	finished_eating = 0;
	while (i < data->total_philos)
	{
		pthread_mutex_lock(&philo[i].meal_mutex);
		if (philo[i].meal_eaten >= data->total_meal)
			finished_eating++;
		pthread_mutex_unlock(&philo[i].meal_mutex);
		i++;
	}
	
	if (finished_eating == data->total_philos)
	{
		pthread_mutex_lock(&data->print_mutex);
		ft_stop_simulation(data);
		pthread_mutex_unlock(&data->print_mutex);
		return (1);
	}
	return (0);
}

void	*ft_police(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo[0].data;

	while (ft_is_running(data))
	{
		// Verificar morte (prioridade)
		if (check_philosopher_death(philo, data))
			return (NULL);
		
		// Verificar se todos comeram o suficiente
		if (check_all_ate_enough(philo, data))
			return (NULL);
		
		usleep(100);
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
