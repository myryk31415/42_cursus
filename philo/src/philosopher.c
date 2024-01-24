/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42heilbronn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:40:09 by padam             #+#    #+#             */
/*   Updated: 2024/01/24 17:32:04 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_state(t_philo *philo, t_state state)
{
	//might have to add mutex to printf
	pthread_mutex_lock(&philo->simulation->print_mutex);
	printf("%ld %d", get_time_ms() - philo->simulation->start_time, philo->id);
	if (state == FORK_TAKEN)
		printf(" has taken a fork\n");
	else if (state == EATING)
		printf(" is eating\n");
	else if (state == SLEEPING)
		printf(" is sleeping\n");
	else if (state == THINKING)
		printf(" is thinking\n");
	else if (state == DEAD)
	{
		printf(" died\n");
		stop_simulation();
	}
	pthread_mutex_unlock(&philo->simulation->print_mutex);
}

/**
 * @brief Checks if the forks are available.
 * @return 1 if the forks are available, 0 if not
*/
int	grab_forks(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->left_fork->mutex) != 0)
		stop_simulation();
	if (pthread_mutex_lock(&philo->right_fork->mutex) != 0)
		stop_simulation();
	if (philo->left_fork->available == 0 || philo->right_fork->available == 0)
	{
		pthread_mutex_unlock(&philo->left_fork->mutex);
		pthread_mutex_unlock(&philo->right_fork->mutex);
		return (0);
	}
	else
	{
		philo->left_fork->available = 0;
		philo->right_fork->available = 0;
		pthread_mutex_unlock(&philo->left_fork->mutex);
		pthread_mutex_unlock(&philo->right_fork->mutex);
		print_state(philo, FORK_TAKEN);
		print_state(philo, FORK_TAKEN);
		print_state(philo, EATING);
		return (1);
	}
}

/**
 * @brief Sets the forks as available.
*/
void	return_forks(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->left_fork->mutex) != 0)
		stop_simulation();
	if (pthread_mutex_lock(&philo->right_fork->mutex) != 0)
		stop_simulation();
	philo->left_fork->available = 1;
	philo->right_fork->available = 1;
	pthread_mutex_unlock(&philo->left_fork->mutex);
	pthread_mutex_unlock(&philo->right_fork->mutex);
	print_state(philo, SLEEPING);
}

/**
 * @brief The philosopher's routine.
 * @param philo_in Struct containing the philosopher's parameters
*/
void	*philosopher(void *philo_in)
{
	t_philo		*philo;

	philo = (t_philo *)(philo_in);
	while (1)
	{
		if (philo->simulation->stop == 1)
			return (NULL);
		if (get_time_ms() - philo->last_eat > philo->simulation->time_to_die)
			print_state(philo, DEAD);
		else if (philo->state == THINKING && grab_forks(philo))
		{
			philo->state = EATING;
			philo->last_eat = get_time_ms();
		}
		else if (philo->state == EATING && get_time_ms() - philo->last_eat
			> philo->simulation->time_to_eat)
		{
			return_forks(philo);
			philo->state = SLEEPING;
			philo->last_sleep = get_time_ms();
		}
		else if (philo->state == SLEEPING && get_time_ms() - philo->last_sleep
			> philo->simulation->time_to_sleep)
		{
			print_state(philo, THINKING);
			philo->state = THINKING;
		}
	}
	return (0);
}
