/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42heilbronn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:43:41 by padam             #+#    #+#             */
/*   Updated: 2024/01/31 20:28:16 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief frees allocated memory and destroys mutexes
*/
void	clean_up(pthread_mutex_t *forks, pthread_t *thread, t_philo *philos, int nb_mutex_destroy)
{
	pthread_mutex_destroy(&philos->simulation->print_mutex);
	pthread_mutex_destroy(&philos->simulation->nb_eat_done_mutex);
	pthread_mutex_destroy(&philos->simulation->nb_quit_mutex);
	while (nb_mutex_destroy)
		pthread_mutex_destroy(&forks[--nb_mutex_destroy]);
	free(forks);
	free(thread);
	free(philos);
}

void	stop_simulation(pthread_mutex_t *forks, pthread_t *thread, t_philo *philos, int nb_mutex_destroy)
/**
 * @brief exits the program cleanly
*/
{
	clean_up(forks, thread, philos, nb_mutex_destroy);
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
 * @brief sleps using usleep, the last 5ms it tests in 100µs intervals
 * @param ms time to sleep in milliseconds
*/
void	sleep_ms(long ms)
{
	long	start;

	start = get_time_ms();
	if (ms > 5)
		usleep((ms - 5) * 1000);
	while (get_time_ms() - start < ms)
		usleep(100);
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
	simulation->died = 0;
	simulation->nb_quit = 0;
	if (pthread_mutex_init(&simulation->print_mutex, NULL))
		exit (1);
	if (pthread_mutex_init(&simulation->nb_eat_done_mutex, NULL))
	{
		pthread_mutex_destroy(&simulation->print_mutex);
		exit (1);
	}
	if (pthread_mutex_init(&simulation->nb_quit_mutex, NULL))
	{
		pthread_mutex_destroy(&simulation->print_mutex);
		pthread_mutex_destroy(&simulation->nb_eat_done_mutex);
		exit (1);
	}
}
