/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42heilbronn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:37:02 by padam             #+#    #+#             */
/*   Updated: 2023/12/06 15:30:29 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	merge_to_a(t_flags *flags)
{
	int	a_count;
	int	b_count;

	a_count = 0;
	b_count = 0;
	if (flags->elements_total - flags->element_count < flags->group_size * 2)
		b_count = 2 * flags->group_size - (flags->elements_total - flags->element_count);
	while ((a_count < flags->group_size || b_count < flags->group_size)
		&& flags->element_count < flags->elements_total)
	{
		if (a_count == flags->group_size && ++b_count)
		{
			push_a(flags);
			rotate_a(flags);
		}
		else if (b_count == flags->group_size && ++a_count)
			rotate_a(flags);
		else if (flags->stack_a[0] < flags->stack_b[0] && ++a_count)
			rotate_a(flags);
		else
		{
			push_a(flags);
			rotate_a(flags);
			b_count++;
		}
		flags->element_count++;
	}
}

void	merge_to_b(t_flags *flags)
{
	int	a_count;
	int	b_count;

	a_count = 0;
	b_count = 0;
	if (flags->elements_total - flags->element_count < flags->group_size * 2)
		b_count = 2 * flags->group_size - (flags->elements_total - flags->element_count);
	while ((a_count < flags->group_size || b_count < flags->group_size)
		&& flags->element_count < flags->elements_total)
	{
		if (a_count == flags->group_size && ++b_count)
			rotate_b(flags);
		else if (b_count == flags->group_size && ++a_count)
		{
			push_b(flags);
			rotate_b(flags);
		}
		else if (flags->stack_a[0] < flags->stack_b[0])
		{
			push_b(flags);
			rotate_b(flags);
			a_count++;
		}
		else if (++b_count)
			rotate_b(flags);
		flags->element_count++;
	}
}

static void	move_to_b(t_flags *flags)
{
	while (flags->element_count < flags->elements_total)
	{
		push_b(flags);
		rotate_b(flags);
		flags->element_count++;
	}
}

static void	move_a(t_flags *flags)
{
	while (flags->element_count < flags->elements_total)
	{
		rotate_a(flags);
		flags->element_count++;
	}
}

static void	merge_groups(t_flags *flags)
{
	int	b_groups;

	// ft_printf("group_size: %d\n", flags->group_size);
	b_groups = flags->size_b / flags->group_size;
	if (flags->size_b % flags->group_size)
		b_groups++;
	flags->element_count = 0;
	// ft_printf("b_groups: %d\n", b_groups);
	while (b_groups > 0)
	{
		if (b_groups)
		{
			merge_to_a(flags);
			b_groups--;
		}
		if (!b_groups)
		{
			move_to_b(flags);
			break ;
		}
		if (b_groups)
		{
			merge_to_b(flags);
			b_groups--;
		}
		if (!b_groups)
			move_a(flags);
	}
	flags->group_size *= 2;
}

int	main(int argc, char **argv)
{
	t_flags	flags;

	flags.group_size = 3;
	flags.elements_total = argc - 1;
	flags.element_count = 0;
	if (argc == 1)
		return (0);
	if (!check_args(argc, argv))
		stop_program("Incorrect arguments", &flags);
	if (!fill_stack(&flags, argc, argv))
		stop_program("Malloc failed", &flags);
	if (argc == 6)
	{
		sort_five(&flags);
		return (0);
	}
	start_sort_three(&flags);
	while (flags.group_size < flags.elements_total)
		merge_groups(&flags);
	// system("leaks push_swap");
	return (0);
}
