/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42heilbronn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:37:02 by padam             #+#    #+#             */
/*   Updated: 2023/12/14 21:37:24 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	merge_to_a(t_flags *flags)
{
	int	a_count;
	int	b_count;
	int	b_rotated;

	a_count = 0;
	b_count = 0;
	b_rotated = 0;
	if (flags->size_b % flags->group_size && flags->element_count == 0)
		b_count = flags->group_size - flags->size_b % flags->group_size;
	while ((a_count < flags->group_size || b_count < flags->group_size)
		&& flags->element_count < flags->elements_total)
	{
		if (a_count == flags->group_size && ++b_count)
		{
			if (!b_rotated)
				reverse_rotate_b(flags);
			push_a(flags);
			b_rotated = 0;
		}
		else if (b_count == flags->group_size && ++a_count)
			reverse_rotate_a(flags);
		else if (!b_rotated && flags->stack_a[flags->size_a - 1] > flags->stack_b[flags->size_b - 1] && ++a_count)
		{
			reverse_rotate_both(flags);
			b_rotated = 1;
		}
		else if (b_rotated && flags->stack_a[flags->size_a - 1] > flags->stack_b[0] && ++a_count)
			reverse_rotate_a(flags);
		else
		{
			if (!b_rotated)
				reverse_rotate_b(flags);
			push_a(flags);
			b_count++;
			b_rotated = 0;
		}
		flags->element_count++;
	}
}

void	merge_to_b(t_flags *flags)
{
	int	a_count;
	int	b_count;
	int	a_rotated;

	a_rotated = 0;
	a_count = 0;
	b_count = 0;
	if (flags->size_b % flags->group_size && flags->element_count == 0)
		b_count = flags->group_size - flags->size_b % flags->group_size;
	while ((a_count < flags->group_size || b_count < flags->group_size)
		&& flags->element_count < flags->elements_total)
	{
		if (a_count == flags->group_size && ++b_count)
			reverse_rotate_b(flags);
		else if (b_count == flags->group_size && ++a_count)
		{
			if (!a_rotated)
				reverse_rotate_a(flags);
			push_b(flags);
			a_rotated = 0;
		}
		else if (!a_rotated && flags->stack_a[flags->size_a - 1] > flags->stack_b[flags->size_b - 1])
		{
			reverse_rotate_a(flags);
			push_b(flags);
			a_count++;
		}
		else if (a_rotated && flags->stack_a[0] > flags->stack_b[flags->size_b - 1])
		{
			push_b(flags);
			a_count++;
			a_rotated = 0;
		}
		else if (++b_count)
		{
			if (!a_rotated)
			{
				reverse_rotate_both(flags);
				a_rotated = 1;
			}
			else
				reverse_rotate_b(flags);
		}
		flags->element_count++;
	}
}

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

	// ft_printf("group_size: %d\n", flags->group_size);
	toggle = 1;
	flags->element_count = 0;
	// ft_printf("b_groups: %d\n", b_groups);
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
	start_sort(&flags);
	while (flags.group_size < flags.elements_total)
		merge_groups(&flags);
	// system("leaks push_swap");
	return (0);
}
