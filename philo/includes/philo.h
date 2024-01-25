/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42heilbronn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:02:02 by padam             #+#    #+#             */
/*   Updated: 2024/01/25 14:24:01 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>

typedef enum e_state
{
	THINKING,
	EATING,
	SLEEPING,
	DEAD,
	FORK_TAKEN,
}	t_state;

typedef struct s_fork
{
	int				available;
	pthread_mutex_t	mutex;
}	t_fork;

typedef struct s_simulation
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_eat;
	long			start_time;
	pthread_mutex_t	nb_eat_done_mutex;
	int				nb_eat_done;
	pthread_mutex_t	print_mutex;
}	t_simulation;

typedef struct s_philo
{
	int				id;
	int				nb_eat;
	long			last_eat;
	long			last_sleep;
	t_fork			*left_fork;
	t_fork			*right_fork;
	t_simulation	*simulation;
	pthread_t		*thread;
	t_state			state;
}	t_philo;

//libft_utils
int		ft_atoi(const char *str);
int		ft_isnumber(char *str);

//philosopher
void	*philosopher(void *philo);

//utils
void	stop_simulation(void);
long	get_time_ms(void);
void	initialize_simulation(t_simulation *simulation, int argc, char **argv);
