/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42heilbronn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:53:03 by padam             #+#    #+#             */
/*   Updated: 2024/01/31 20:20:59 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	will_starve(t_philo *philo, long ms)
{
	long	time_till_starve;

	time_till_starve = philo->last_eat + philo->simulation->time_to_die
		- get_time_ms();
	if (ms > time_till_starve)
	{
		sleep_ms(time_till_starve);
		philo->state = DEAD;
		print_state(philo);
		philo->simulation->died = 1;
		return (1);
	}
	return (0);
}

/**
 * @brief locks the philosopher's forks
*/
static void	take_forks(t_philo *philo)
{
	philo->state = TAKE_FORK;
	if (pthread_mutex_lock(philo->left_fork)
		|| pthread_mutex_lock(philo->right_fork))
		philo->simulation->error = 1;
	print_state(philo);
	print_state(philo);
}

/**
 * @brief sets the philosopher's state to eating and eats for the given time
 * @return 1 if the philosopher died, 0 if not
*/
int	philo_eat(t_philo *philo)
{
	take_forks(philo);
	philo->state = EATING;
	print_state(philo);
	philo->last_eat = get_time_ms();
	if (will_starve(philo, philo->simulation->time_to_eat))
		return (1);
	sleep_ms(philo->simulation->time_to_eat);
	if (pthread_mutex_unlock(philo->left_fork)
		|| pthread_mutex_unlock(philo->right_fork))
		philo->simulation->error = 1;
	if (philo->simulation->nb_eat != -1)
		philo->nb_eat++;
	if (philo->nb_eat == philo->simulation->nb_eat)
	{
		if (pthread_mutex_lock(&philo->simulation->nb_eat_done_mutex))
			philo->simulation->error = 1;
		philo->simulation->nb_eat_done++;
		if (pthread_mutex_unlock(&philo->simulation->nb_eat_done_mutex))
			philo->simulation->error = 1;
	}
	return (0);
}

/**
 * @brief sets the philosopher's state to sleeping and sleeps for the given time
 * @return 1 if the philosopher died, 0 if not
*/
int	philo_sleep(t_philo *philo)
{
	philo->state = SLEEPING;
	print_state(philo);
	philo->last_sleep = get_time_ms();
	if (will_starve(philo, philo->simulation->time_to_sleep))
		return (1);
	sleep_ms(philo->simulation->time_to_sleep);
	return (0);
}

/**
 * @brief sets the philosopher's state to thinking
*/
int	philo_think(t_philo *philo)
{
	philo->state = THINKING;
	print_state(philo);
	return (0);
}
