/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42heilbronn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:02:02 by padam             #+#    #+#             */
/*   Updated: 2024/01/23 16:31:48 by padam            ###   ########.fr       */
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
	int		nb_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		nb_eat;
	long	start_time;
}	t_parameters;

typedef struct s_philo
{
	int				id;
	int				nb_eat;
	long			last_eat;
	t_fork			*left_fork;
	t_fork			*right_fork;
	t_parameters	params;
	pthread_t		thread;
}	t_philo;

//libft_utils
int	ft_atoi(const char *str);
int	ft_isnumber(char *str);

//philosopher
int	philosopher(t_philo *philo);

//utils
long	get_time_ms(void);
