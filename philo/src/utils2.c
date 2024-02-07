/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42heilbronn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:48:59 by padam             #+#    #+#             */
/*   Updated: 2024/02/07 14:49:12 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief allocates threads, forks and philosophers
*/
void	malloc_vars(pthread_mutex_t **forks, pthread_t **threads,
	t_philo **philos, int nb_philo)
{
	*philos = NULL;
	*forks = NULL;
	*threads = NULL;
	*philos = malloc(sizeof(t_philo) * nb_philo);
	if (!*philos)
		stop_simulation(*philos, 0);
	*forks = malloc(sizeof(pthread_mutex_t) * nb_philo);
	(*philos)->left_fork = *forks;
	if (!*forks)
		stop_simulation(*philos, 0);
	*threads = malloc(sizeof(pthread_t) * nb_philo);
	(*philos)->thread = *threads;
	if (!*threads)
		stop_simulation(*philos, 0);
	if (pthread_mutex_init(&(*forks)[0], NULL))
		stop_simulation(*philos, 1);
}
