/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42heilbronn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:37:02 by padam             #+#    #+#             */
/*   Updated: 2023/11/24 16:27:35 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_flags	flags;

	if (!check_args(argc, argv))
	{
		stop_program("Incorrect arguments", &flags);
		return (0);
	}
	if (!fill_stack(&flags, argc, argv))
	{
		stop_program("Malloc failed", &flags);
		return (0);
	}
	return (1);
}
