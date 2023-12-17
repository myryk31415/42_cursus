/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_to_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42heilbronn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:32:04 by padam             #+#    #+#             */
/*   Updated: 2023/12/17 19:24:21 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	try_rotate_a(int b_rotated, t_flags *flags)
{
	if (!b_rotated && flags->stack_a[flags->size_a - 1]
		> flags->stack_b[flags->size_b - 1])
		reverse_rotate_both(flags);
	else if (b_rotated && flags->stack_a[flags->size_a - 1] > flags->stack_b[0])
		reverse_rotate_a(flags);
	else
		return (0);
	return (1);
}

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
			b_rotated = push_to_a(b_rotated, flags);
		else if (b_count == flags->group_size && ++a_count)
			reverse_rotate_a(flags);
		else if (try_rotate_a(b_rotated, flags))
		{
			b_rotated = 1;
			a_count++;
		}
		else if (++b_count)
			b_rotated = push_to_a(b_rotated, flags);
		flags->element_count++;
	}
}

static int	push_to_b(int a_rotated, t_flags *flags)
{
	if (!a_rotated)
		reverse_rotate_a(flags);
	push_b(flags);
	return (0);
}

static int	try_rotate_b(int a_rotated, t_flags *flags)
{
	if (!a_rotated && flags->stack_a[flags->size_a - 1]
		< flags->stack_b[flags->size_b - 1])
		reverse_rotate_both(flags);
	else if (a_rotated && flags->stack_a[0] < flags->stack_b[flags->size_b - 1])
		reverse_rotate_b(flags);
	else
		return (0);
	return (1);
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
			a_rotated = push_to_b(a_rotated, flags);
		else if (try_rotate_b(a_rotated, flags))
		{
			a_rotated = 1;
			b_count++;
		}
		else if (++a_count)
			a_rotated = push_to_b(a_rotated, flags);
		flags->element_count++;
	}
}
