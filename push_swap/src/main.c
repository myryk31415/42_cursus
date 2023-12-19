/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42heilbronn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:37:02 by padam             #+#    #+#             */
/*   Updated: 2023/12/19 14:14:02 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_to_b(t_flags *flags)
{
	int	i;

	i = flags->elements_total % (flags->group_size * 2);
	while (i--)
	{
		reverse_rotate_a(flags);
		push_b(flags);
		flags->element_count++;
	}
}

static void	move_a(t_flags *flags)
{
	int	i;

	i = flags->elements_total % (flags->group_size * 2);
	while (i--)
	{
		reverse_rotate_a(flags);
		flags->element_count++;
	}
}

static void	merge_groups(t_flags *flags)
{
	int	toggle;

	toggle = 1;
	flags->element_count = 0;
	if (flags->elements_total % (flags->group_size * 4) > flags->group_size * 2
		|| flags->elements_total % (flags->group_size * 4) == 0)
		toggle *= -1;
	if (flags->elements_total % (flags->group_size * 2) <= flags->group_size
		&& flags->elements_total % (flags->group_size * 2) != 0)
	{
		if (toggle == 1)
			move_a(flags);
		else
			move_to_b(flags);
		toggle *= -1;
	}
	while (flags->element_count < flags->elements_total)
	{
		if (toggle == 1)
			merge_to_a(flags);
		else
			merge_to_b(flags);
		toggle *= -1;
	}
	flags->group_size *= 2;
}

int	main(int argc, char **argv)
{
	t_flags	flags;

	flags.group_size = 4;
	flags.elements_total = argc - 1;
	flags.element_count = 0;
	flags.stack_a = NULL;
	flags.stack_b = NULL;
	if (argc == 1)
		return (0);
	if (!check_args(argc, argv))
		stop_program(&flags);
	if (!fill_stack(&flags, argc, argv))
		stop_program(&flags);
	if (is_sorted(&flags))
		return (0);
	if (argc <= 4 || argc == 6)
	{
		sort_small(&flags);
		return (0);
	}
	start_sort(&flags);
	while (flags.group_size < flags.elements_total)
		merge_groups(&flags);
	return (0);
}
