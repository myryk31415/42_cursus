/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42heilbronn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:53:19 by padam             #+#    #+#             */
/*   Updated: 2024/02/07 16:19:59 by padam            ###   ########.fr       */
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

static void	init_philo(pthread_mutex_t *forks, t_philo *philos,
		t_simulation *simulation, int i)
{
	usleep(10);
	philos[i].nb_eat = 0;
	philos[i].simulation = simulation;
	philos[i].last_eat = simulation->start_time;
	philos[i].last_sleep = simulation->start_time;
	philos[i].id = i + 1;
	philos[i].state = THINKING;
	if ((i + 1) != simulation->nb_philo
		&& pthread_mutex_init(&forks[i + 1], NULL))
		stop_simulation(philos, i + 1);
	philos[i].left_fork = &forks[i];
	philos[i].right_fork = &forks[(i + 1) % simulation->nb_philo];
}

/**
 * @brief Checks if a philosopher has died or an error has occured.
*/
static void	simulation_watcher(t_simulation *simulation, t_philo *philos)
{
	int	i;

	i = 0;
	usleep(500);
	while (i < simulation->nb_philo && simulation->died == 0)
	{
		if (get_time_ms() - philos[i].last_eat
			> simulation->time_to_die)
		{
			simulation->died = 1;
			philos[i].state = DEAD;
			print_state(&philos[i]);
		}
		i++;
	}
	if (simulation->error == 1)
		stop_simulation(philos, simulation->nb_philo);
}

/**
 * @brief Starts a thread for each philosopher, passing it its parameters.
 * @param simulation Input parameters of the simulation
*/
static int	start_threads(t_simulation *simulation)
{
	int				i;
	pthread_mutex_t	*forks;
	pthread_t		*threads;
	t_philo			*philos;

	i = 0;
	malloc_vars(&forks, &threads, &philos, simulation->nb_philo);
	simulation->start_time = get_time_ms();
	while (i < simulation->nb_philo)
	{
		init_philo(forks, philos, simulation, i);
		philos[i].thread = &threads[i];
		if (pthread_create(&threads[i], NULL, philosopher, &philos[i])
			|| pthread_detach(threads[i]))
			stop_simulation(philos, i);
		i++;
	}
	while (simulation->died == 0
		&& simulation->nb_eat_done != simulation->nb_philo)
		simulation_watcher(simulation, philos);
	while (simulation->nb_quit < simulation->nb_philo)
		if (simulation->error == 1)
			stop_simulation(philos, simulation->nb_philo);
	clean_up(philos, simulation->nb_philo);
	return (0);
}

/**
 * @brief Simulates philosophers eating, sleeping and thinking.
 * Each philospher is a thread, they share forks protected by mutexes.
*/
int	main(int argc, char **argv)
{
	t_simulation	simulation;

	simulation.error = 0;
	simulation.died = 0;
	if (input_check(argc, argv))
		return (1);
	if (argc == 6 && ft_atoi(argv[5]) == 0)
		return (0);
	if (ft_atoi(argv[1]) == 1)
	{
		printf("0 1 has taken a fork\n");
		sleep_ms(ft_atoi(argv[2]));
		printf("%i 1 died\n", ft_atoi(argv[2]));
		return (0);
	}
	initialize_simulation(&simulation, argc, argv);
	start_threads(&simulation);
	return (0);
}
