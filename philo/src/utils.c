/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42heilbronn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:43:41 by padam             #+#    #+#             */
/*   Updated: 2024/01/24 16:57:43 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief exits the program cleanly
*/
void	stop_simulation(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

/**
 * @brief gets the currrent time with millisecond precision
*/
long	get_time_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

/**
 * @brief Takes the input numbers and stores them in the simulation struct
*/
void	initialize_simulation(t_simulation *simulation, int argc, char **argv)
{
	simulation->nb_philo = ft_atoi(argv[1]);
	simulation->time_to_die = ft_atoi(argv[2]);
	simulation->time_to_eat = ft_atoi(argv[3]);
	simulation->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		simulation->nb_eat = ft_atoi(argv[5]);
	else
		simulation->nb_eat = -1;
	simulation->nb_eat_done = 0;
	if (pthread_mutex_init(&simulation->print_mutex, NULL) != 0)
		stop_simulation();
	if (pthread_mutex_init(&simulation->nb_eat_done_mutex, NULL) != 0)
		stop_simulation();
}
