/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42heilbronn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:18:18 by padam             #+#    #+#             */
/*   Updated: 2023/11/30 18:20:45 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	start_sort(t_flags *flags)
// {
// 	int	i;

// 	i = 0;
// 	while (i++ < flags->elements_total / 2)
// 		push_b(flags);
// }

static void	rest_to_b(t_flags *flags)
{
	if (flags->element_count == flags->elements_total - 2)
	{
		if (flags->stack_a[0] > flags->stack_a[1])
		{
			push_b(flags);
			push_b(flags);
			rotate_b(flags);
		}
		else
		{
			push_b(flags);
			rotate_b(flags);
			push_b(flags);
		}
		rotate_b(flags);
	}
	else if (flags->element_count == flags->elements_total - 1)
	{
		push_b(flags);
		rotate_b(flags);
	}
}

static void	rest_to_a(t_flags *flags)
{
	if (flags->element_count == flags->elements_total - 2)
	{
		if (flags->stack_a[0] > flags->stack_a[1])
			swap_a(flags);
		rotate_a(flags);
		rotate_a(flags);
	}
	else if (flags->element_count == flags->elements_total - 1)
		rotate_a(flags);
}

static void	sort_to_b(t_flags *flags)
{
	if (flags->stack_a[0] < flags->stack_a[1])
		swap_a(flags);
	push_b(flags);
	push_b(flags);
	if (flags->stack_a[0] < flags->stack_b[0])
	{
		push_b(flags);
		rotate_b(flags);
		rotate_b(flags);
	}
	else
	{
		rotate_b(flags);
		if (flags->stack_a[0] < flags->stack_b[0])
		{
			push_b(flags);
			rotate_b(flags);
		}
		else
		{
			rotate_b(flags);
			push_b(flags);
		}
	}
	rotate_b(flags);
}

static void	sort_to_a(t_flags *flags)
{
	if (flags->stack_a[0] > flags->stack_a[2])
	{
		push_b(flags);
		if (flags->stack_a[0] > flags->stack_a[1])
			swap_a(flags);
		rotate_a(flags);
		if (flags->stack_a[0] > flags->stack_b[0])
		{
			push_a(flags);
			rotate_a(flags);
		}
		else
		{
			rotate_a(flags);
			push_a(flags);
		}
		rotate_a(flags);
	}
	else
	{
		if (flags->stack_a[0] > flags->stack_a[1])
			swap_a(flags);
		rotate_a(flags);
		if (flags->stack_a[0] > flags->stack_a[1])
			swap_a(flags);
		rotate_a(flags);
		rotate_a(flags);
	}
}

void	start_sort_three(t_flags *flags)
{
	int	toggle;

	toggle = 1;
	while (flags->element_count <= flags->elements_total - 3)
	{
		if (toggle == 1)
			sort_to_a(flags);
		else
			sort_to_b(flags);
		toggle *= -1;
		flags->element_count += 3;
	}
	if (toggle == 1)
		rest_to_a(flags);
	else
		rest_to_b(flags);
}
