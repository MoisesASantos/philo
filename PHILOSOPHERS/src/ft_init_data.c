/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 12:06:05 by mosantos          #+#    #+#             */
/*   Updated: 2025/10/16 12:06:08 by mosantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

size_t	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

static int	ft_get_args(int argc, char **argv, t_data *data)
{
	int	error;

	error = 1;
	if (argc != 5 && argc != 6)
		return (0);
	data->total_philos = ft_atoll(argv[1], &error);
	data->time_to_die = ft_atoll(argv[2], &error);
	data->time_to_eat = ft_atoll(argv[3], &error);
	data->time_to_sleep = ft_atoll(argv[4], &error);
	if (argc == 6)
		data->total_meal = ft_atoll(argv[5], &error);
	else
		data->total_meal = -1;
	if (!error || data->time_to_die <= 0 || data->total_philos <= 0
				|| data->time_to_eat <= 0 || data->time_to_sleep <= 0)
		return (0);
	return (1);
}

int	ft_create_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->total_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			while (--i >= 0)
				pthread_mutex_destroy(&data->forks[i]);
			free(data->forks);
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_init_data(int argc, char **argv, t_data *data)
{
	if (!ft_get_args(argc, argv, data))
		return (0);
	data->stop = 0;
	data->start_time = get_time();
	data->forks = malloc(sizeof(pthread_mutex_t) * data->total_philos);
	if (!data->forks)
		return (0);
	if (pthread_mutex_init(&data->print_mutex, NULL) != 0)
		return (free(data->forks), 0);
	if (pthread_mutex_init(&data->stop_mutex, NULL) != 0)
		return (pthread_mutex_destroy(&data->print_mutex), free(data->forks), 0);
	if (!ft_create_mutex(data))
		return (pthread_mutex_destroy(&data->print_mutex), pthread_mutex_destroy(&data->stop_mutex), 0);
	data->time_to_think = data->time_to_die - data->time_to_eat - data->time_to_sleep;
	if ((long)data->time_to_think < 0)
		data->time_to_think = 0;
	return (1);
}

int	ft_init_philo(t_philo **philo, t_data *data)
{
	int	i;

	*philo = malloc(sizeof(t_philo) * data->total_philos);
	if (!*philo)
		return (0);
	i = 0;
	while (i < data->total_philos)
	{
		(*philo)[i].ID = i + 1;
		(*philo)[i].last_meal_time = data->start_time;
		(*philo)[i].meal_eaten = 0;
		(*philo)[i].data = data;
		(*philo)[i].left_fork = &data->forks[i];
		(*philo)[i].right_fork =  &data->forks[(i + 1) % data->total_philos];
		if (pthread_mutex_init(&(*philo)[i].meal_mutex, NULL) != 0)
		{
			while (--i >= 0)
				pthread_mutex_destroy(&(*philo)[i].meal_mutex);
			return (0);
		}
		i++;
	}
	return (1);
}
