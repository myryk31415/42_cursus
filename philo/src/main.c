/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42heilbronn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:53:19 by padam             #+#    #+#             */
/*   Updated: 2024/01/11 15:15:48 by padam            ###   ########.fr       */
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
	}
	if (ft_atoi(argv[1]) == 0)
		return (1);
	return (0);
}

static int	start_threads(t_parameters params)
{
	int	i;
	t_fork	*forks;

	i = 0;
	forks = malloc(sizeof(t_fork) * params.nb_philo);
	if (!forks)
		return (1);
	while (i < params.nb_philo)
	{

	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_parameters	params;

	if (input_check(argc, argv))
		return (1);
	params.nb_philo = ft_atoi(argv[1]);
	params.time_to_die = ft_atoi(argv[2]);
	params.time_to_eat = ft_atoi(argv[3]);
	params.time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		params.nb_eat = ft_atoi(argv[5]);
	else
		params.nb_eat = -1;
	return (0);
}
