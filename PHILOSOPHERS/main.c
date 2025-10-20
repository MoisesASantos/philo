/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:14:21 by mosantos          #+#    #+#             */
/*   Updated: 2025/10/15 15:14:24 by mosantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/philo.h"

int main(int argc, char **argv)
{
	t_philo	*philo;
	t_data	data;
	int		i;

	if (!ft_init_data(argc, argv, &data))
		return (ft_putendl_fd("Wrong Args", 2), 1);
	if (!ft_init_philo(&philo, &data))
		return (ft_free_all(&data, philo), 1);
	if (!ft_init_thread(philo, &data))
		return (1);
	i = 0;
	while (i < data.total_philos)
    	pthread_detach(philo[i++].thread);
	pthread_join(data.monitor_thread, NULL);
	return (0);
}
