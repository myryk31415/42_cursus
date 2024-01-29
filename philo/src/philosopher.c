/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42heilbronn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:40:09 by padam             #+#    #+#             */
/*   Updated: 2024/01/29 13:49:26 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	print_state(t_philo *philo, t_state state)
// {
// 	pthread_mutex_lock(&philo->simulation->print_mutex);
// 	printf("%ld %d", get_time_ms() - philo->simulation->start_time, philo->id);
// 	if (state == FORK_TAKEN)
// 		printf(" has taken a fork\n");
// 	else if (state == EATING)
// 		printf(" is eating\n");
// 	else if (state == SLEEPING)
// 		printf(" is sleeping\n");
// 	else if (state == THINKING)
// 		printf(" is thinking\n");
// 	else if (state == DEAD)
// 	{
// 		printf(" died\n");
// 		stop_simulation();
// 	}
// 	pthread_mutex_unlock(&philo->simulation->print_mutex);
// }

void	print_state(t_philo *philo)
{
	long	time;

	time = get_time_ms() - philo->simulation->start_time;
	pthread_mutex_lock(&philo->simulation->print_mutex);
	printf("%ld %d", time, philo->id);
	if (philo->state == FORK_TAKEN)
		printf(" has taken a fork\n");
	else if (philo->state == EATING)
		printf(" is eating\n");
	else if (philo->state == SLEEPING)
		printf(" is sleeping\n");
	else if (philo->state == THINKING)
		printf(" is thinking\n");
	else if (philo->state == DEAD)
		printf(" died\n");
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
		philo->state = FORK_TAKEN;
		pthread_mutex_unlock(&philo->left_fork->mutex);
		print_state(philo);
		pthread_mutex_unlock(&philo->right_fork->mutex);
		print_state(philo);
		philo->state = EATING;
		print_state(philo);
		philo->last_eat = get_time_ms();
		sleep_ms(philo->simulation->time_to_eat);
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
	philo->state = SLEEPING;
	print_state(philo);
	philo->last_sleep = get_time_ms();
	sleep_ms(philo->simulation->time_to_sleep);
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
		usleep(100);
		if (philo->simulation->died == 1)
		{
			philo->simulation->nb_eat_done++;
			return (NULL);
		}
		if (philo->simulation->nb_eat_done >= philo->simulation->nb_philo)
		{
			pthread_mutex_lock(&philo->simulation->nb_eat_done_mutex);
			philo->simulation->nb_eat_done++;
			pthread_mutex_unlock(&philo->simulation->nb_eat_done_mutex);
			return (NULL);
		}
		if (get_time_ms() - philo->last_eat > philo->simulation->time_to_die)
		{
			philo->state = DEAD;
			print_state(philo);
			philo->simulation->died = 1;
		}
		else if (philo->state == THINKING && grab_forks(philo))
			philo->state = EATING;
		else if (philo->state == EATING && get_time_ms() - philo->last_eat
			> philo->simulation->time_to_eat)
		{
			if (philo->simulation->nb_eat != -1)
				philo->nb_eat++;
			if (philo->nb_eat == philo->simulation->nb_eat)
			{
				pthread_mutex_lock(&philo->simulation->nb_eat_done_mutex);
				philo->simulation->nb_eat_done++;
				pthread_mutex_unlock(&philo->simulation->nb_eat_done_mutex);
			}
			return_forks(philo);
			philo->state = SLEEPING;
		}
		else if (philo->state == SLEEPING && get_time_ms() - philo->last_sleep
			> philo->simulation->time_to_sleep)
		{
			philo->state = THINKING;
			print_state(philo);
		}
	}
	return (NULL);
}
