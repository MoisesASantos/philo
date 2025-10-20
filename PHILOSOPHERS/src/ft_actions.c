/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 12:16:41 by mosantos          #+#    #+#             */
/*   Updated: 2025/10/20 12:16:44 by mosantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_take_forks(t_philo *philo)
{
	if (philo->ID % 2 == 0 && ft_is_running(philo->data))
	{
		pthread_mutex_lock(philo->right_fork);
		ft_print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		ft_print_status(philo, "has taken a fork");
	}
	else if (philo->ID % 2 != 2 && ft_is_running(philo->data))
	{
		pthread_mutex_lock(philo->left_fork);
		ft_print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		ft_print_status(philo, "has taken a fork");
	}
}

void	ft_realese_fork(t_philo *philo)
{
	if (!ft_is_running(philo->data))
		return ;
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	ft_eating(t_philo *philo)
{
	if (!ft_is_running(philo->data))
		return ;
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal_time = get_time();
	philo->meal_eaten++;
	pthread_mutex_unlock(&philo->meal_mutex);
	ft_print_status(philo, "is eating");
	ft_usleep(philo->data->time_to_eat);
}

void	ft_sleep(t_philo *philo)
{
	if (!ft_is_running(philo->data))
		return ;
	ft_print_status(philo, "is sleeping");
	ft_usleep(philo->data->time_to_sleep);
}

void	ft_thinking(t_philo *philo)
{
	if (!ft_is_running(philo->data))
		return ;
	ft_print_status(philo, "is thinking");
	ft_usleep(philo->data->time_to_think);
}