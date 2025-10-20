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
    t_philo *philo;
    t_data  data;
    int     i;

    if (!ft_init_data(argc, argv, &data))
        return (ft_putendl_fd("Wrong Args", 2), 1);
    if (!ft_init_philo(&philo, &data))
        return (ft_free_all(&data, philo), 1);
    
    // Caso especial: 1 filósofo
    if (data.total_philos == 1)
    {
        printf("0 1 has taken a fork\n");
        ft_usleep(data.time_to_die);
        printf("%zu 1 died\n", data.time_to_die);
        ft_free_all(&data, philo);
        return (0);
    }
    
    if (!ft_init_thread(philo, &data))
        return (1);
    
    // Não use detach, use join em todas as threads
    pthread_join(data.monitor_thread, NULL);
    
    i = 0;
    while (i < data.total_philos)
        pthread_join(philo[i++].thread, NULL);
    
    // Liberar todos os recursos
    ft_free_all(&data, philo);
    
    return (0);
}
