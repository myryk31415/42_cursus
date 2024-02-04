/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42heilbronn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:40:09 by padam             #+#    #+#             */
/*   Updated: 2024/02/04 11:38:43 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Prints time in ms, philosopher id and action.
*/
void	print_state(t_philo *philo)
{
	long	time;

	time = get_time_ms() - philo->simulation->start_time;
	if (pthread_mutex_lock(&philo->simulation->print_mutex))
		philo->simulation->error = 1;
	printf("%ld %d", time, philo->id);
	if (philo->state == TAKE_FORK)
		printf(" has taken a fork\n");
	else if (philo->state == EATING)
		printf(" is eating\n");
	else if (philo->state == SLEEPING)
		printf(" is sleeping\n");
	else if (philo->state == THINKING)
		printf(" is thinking\n");
	else if (philo->state == DEAD)
		printf(" died\n");
	if (pthread_mutex_unlock(&philo->simulation->print_mutex))
		philo->simulation->error = 1;
}

/**
 * @brief Checks if a philosopher died or enough meals were eaten
 * @return 1 if the simulation is over, 0 if not
*/
int	is_end_of_sim(t_philo *philo)
{
	if (philo->simulation->died == 1)
		return (1);
	if (philo->simulation->nb_eat_done == philo->simulation->nb_philo)
		return (1);
	return (0);
}

/**
 * @brief The philosopher's routine.
 * @param philo_in Struct containing the philosopher's parameters
*/
void	*philosopher(void *philo_in)
{
	t_philo		*philo;

	philo = (t_philo *)(philo_in);
	while (philo->simulation->nb_eat_done < philo->simulation->nb_philo)
	{
		if (philo_eat(philo) || is_end_of_sim(philo))
			break ;
		if (philo_sleep(philo) || is_end_of_sim(philo))
			break ;
		if (philo_think(philo) || is_end_of_sim(philo))
			break ;
	}
	if (pthread_mutex_lock(&philo->simulation->nb_quit_mutex))
		philo->simulation->error = 1;
	philo->simulation->nb_quit++;
	if (pthread_mutex_unlock(&philo->simulation->nb_quit_mutex))
		philo->simulation->error = 1;
	return (NULL);
}
