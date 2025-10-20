/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:49:02 by mosantos          #+#    #+#             */
/*   Updated: 2025/10/15 14:49:06 by mosantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include	<unistd.h>
# include	<pthread.h>
# include	<sys/time.h>
# include	<limits.h>
# include	<stdlib.h>
# include	<stdio.h>

typedef struct s_data
{
	size_t	time_to_die;
	size_t	time_to_eat;
	size_t	time_to_think;
	size_t	time_to_sleep;
	size_t	start_time;
	int		total_philos;
	int		total_meal;
	int		stop;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	stop_mutex;
	pthread_t	monitor_thread;
}	t_data;

typedef struct s_philo
{
	int		ID;
	int		meal_eaten;
	pthread_t	thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	meal_mutex;
	size_t	last_meal_time;
	t_data	*data;
}	t_philo;

void	ft_stop_simulation(t_data *data);
void	ft_putendl_fd(char *s, int fd);
void	ft_free_all(t_data *data, t_philo *philo);
void	ft_take_forks(t_philo *philo);
void	ft_sleep(t_philo *philo);
void	ft_realese_fork(t_philo *philo);
void	ft_eating(t_philo *philo);
void	ft_thinking(t_philo *philo);
void	ft_print_status(t_philo *philo, const char *str);
void	ft_cleanup_threads(t_data *data, t_philo *philo, int created);
size_t	get_time(void);
size_t	ft_atoll(const char *nptr, int *error_flag);
int		ft_is_running(t_data *data);
int		ft_init_data(int argc, char **argv, t_data *data);
int		ft_init_philo(t_philo **philo, t_data *data);
int		ft_init_thread(t_philo *philo, t_data *data);
int		ft_usleep(size_t milliseconds);

#endif