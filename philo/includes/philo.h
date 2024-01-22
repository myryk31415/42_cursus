/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42heilbronn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:02:02 by padam             #+#    #+#             */
/*   Updated: 2024/01/22 14:46:13 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <sys/time.h>

typedef struct s_fork
{
	int				available;
	pthread_mutex_t	mutex;
}	t_fork;

typedef struct s_parameters
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_eat;
}	t_parameters;

//philosopher
int	philosopher(void);

//utils
int	ft_atoi(const char *str);
int	ft_isnumber(char *str);
