/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42heilbronn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:02:02 by padam             #+#    #+#             */
/*   Updated: 2024/01/29 16:10:00 by padam            ###   ########.fr       */
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
	TAKE_FORK,
}	t_state;

typedef struct s_simulation
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_eat;
	int				died;
	long			start_time;
	pthread_mutex_t	nb_eat_done_mutex;
	int				nb_eat_done;
	pthread_mutex_t	nb_quit_mutex;
	int				nb_quit;
	pthread_mutex_t	print_mutex;
}	t_simulation;

typedef struct s_philo
{
	int				id;
	int				nb_eat;
	long			last_eat;
	long			last_sleep;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_simulation	*simulation;
	pthread_t		*thread;
	t_state			state;
}	t_philo;

//libft_utils
int		ft_atoi(const char *str);
int		ft_isnumber(char *str);

//philo_actions
int		philo_eat(t_philo *philo);
int		philo_sleep(t_philo *philo);
int		philo_think(t_philo *philo);

//philosopher
void	print_state(t_philo *philo);
void	*philosopher(void *philo);

//utils
void	stop_simulation(void);
long	get_time_ms(void);
void	sleep_ms(long ms);
void	initialize_simulation(t_simulation *simulation, int argc, char **argv);
