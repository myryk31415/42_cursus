/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42heilbronn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:53:19 by padam             #+#    #+#             */
/*   Updated: 2024/01/29 16:13:50 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Check if the numbers positive and if there is at least one philosopher.
 * @return 0 if valid, 1 if not
*/
static int	input_check(int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
		return (1);
	i = 1;
	while (i < argc)
	{
		if (ft_isnumber(argv[i]) == 0 || ft_atoi(argv[i]) < 0)
			return (1);
		i++;
	}
	if (ft_atoi(argv[1]) == 0)
		return (1);
	return (0);
}

/**
 * @brief Starts a thread for each philosopher, passing it its parameters.
 * @param simulation Input parameters of the simulation
*/
static int	start_threads(t_simulation *simulation)
{
	int				i;
	pthread_mutex_t	*forks;
	pthread_t		*thread;
	t_philo			*philos;

	i = 0;
	forks = malloc(sizeof(pthread_mutex_t) * simulation->nb_philo);
	thread = malloc(sizeof(pthread_t) * simulation->nb_philo);
	philos = malloc(sizeof(t_philo) * simulation->nb_philo);
	if (!forks || !thread || !philos)
		return (1);
	simulation->start_time = get_time_ms();
	while (i < simulation->nb_philo)
	{
		philos[i].nb_eat = 0;
		philos[i].simulation = simulation;
		philos[i].last_eat = simulation->start_time;
		philos[i].last_sleep = simulation->start_time;
		philos[i].id = i + 1;
		pthread_mutex_init(&forks[i], NULL);
		philos[i].left_fork = &forks[i];
		philos[i].right_fork = &forks[(i + 1) % simulation->nb_philo];
		philos[i].thread = &thread[i];
		philos[i].state = THINKING;
		pthread_create(&thread[i], NULL, philosopher, &philos[i]);
		pthread_detach(thread[i]);
		i++;
	}
	return (0);
}

/**
 * @brief Simulates philosophers eating, sleeping and thinking.
 * Each philospher is a thread, they share forks protected by mutexes.
*/
int	main(int argc, char **argv)
{
	t_simulation	simulation;

	if (input_check(argc, argv))
		return (1);
	if (argc == 6 && ft_atoi(argv[5]) == 0)
		return (0);
	initialize_simulation(&simulation, argc, argv);
	start_threads(&simulation);
	while (simulation.died == 0
		&& simulation.nb_eat_done != simulation.nb_philo)
		;
	pthread_mutex_lock(&simulation.print_mutex);
	printf("\n\n\n");
	printf("%ldms %d philosophers ate %d times each\n",
		get_time_ms() - simulation.start_time, simulation.nb_philo,
		simulation.nb_eat);
	printf("\n\n\n");
	pthread_mutex_unlock(&simulation.print_mutex);
	while (simulation.nb_quit < simulation.nb_philo)
		;
	return (0);
}
