/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42heilbronn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:18:18 by padam             #+#    #+#             */
/*   Updated: 2023/12/14 21:51:51 by padam            ###   ########.fr       */
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

// static void	rest_to_b(t_flags *flags)
// {
// 	if (flags->element_count == flags->elements_total - 2)
// 	{
// 		if (flags->stack_a[0] > flags->stack_a[1])
// 		{
// 			push_b(flags);
// 			push_b(flags);
// 			rotate_b(flags);
// 		}
// 		else
// 		{
// 			push_b(flags);
// 			rotate_b(flags);
// 			push_b(flags);
// 		}
// 		rotate_b(flags);
// 	}
// 	else if (flags->element_count == flags->elements_total - 1)
// 	{
// 		push_b(flags);
// 		rotate_b(flags);
// 	}
// }

// static void	rest_to_a(t_flags *flags)
// {
// 	if (flags->element_count == flags->elements_total - 2)
// 	{
// 		if (flags->stack_a[0] > flags->stack_a[1])
// 			swap_a(flags);
// 		rotate_a(flags);
// 		rotate_a(flags);
// 	}
// 	else if (flags->element_count == flags->elements_total - 1)
// 		rotate_a(flags);
// }

// static void	sort_to_b(t_flags *flags)
// {
// 	if (flags->stack_a[0] < flags->stack_a[1])
// 		swap_a(flags);
// 	push_b(flags);
// 	push_b(flags);
// 	if (flags->stack_a[0] < flags->stack_b[0])
// 	{
// 		push_b(flags);
// 		rotate_b(flags);
// 		rotate_b(flags);
// 	}
// 	else
// 	{
// 		rotate_b(flags);
// 		if (flags->stack_a[0] < flags->stack_b[0])
// 		{
// 			push_b(flags);
// 			rotate_b(flags);
// 		}
// 		else
// 		{
// 			rotate_b(flags);
// 			push_b(flags);
// 		}
// 	}
// 	rotate_b(flags);
// }

// static void	sort_to_a(t_flags *flags)
// {
// 	if (flags->stack_a[0] > flags->stack_a[2])
// 	{
// 		push_b(flags);
// 		if (flags->stack_a[0] > flags->stack_a[1])
// 			swap_a(flags);
// 		rotate_a(flags);
// 		if (flags->stack_a[0] > flags->stack_b[0])
// 		{
// 			push_a(flags);
// 			rotate_a(flags);
// 		}
// 		else
// 		{
// 			rotate_a(flags);
// 			push_a(flags);
// 		}
// 		rotate_a(flags);
// 	}
// 	else
// 	{
// 		if (flags->stack_a[0] > flags->stack_a[1])
// 			swap_a(flags);
// 		rotate_a(flags);
// 		if (flags->stack_a[0] > flags->stack_a[1])
// 			swap_a(flags);
// 		rotate_a(flags);
// 		rotate_a(flags);
// 	}
// }

static void	push_group_b(t_flags *flags)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		push_b(flags);
		i++;
	}
}

static void	try_swap(t_flags *flags)
{
	if (flags->stack_a[0] > flags->stack_a[1]
		&& flags->stack_b[0] > flags->stack_b[1])
		swap_both(flags);
	if (flags->stack_a[0] > flags->stack_a[1])
		swap_a(flags);
	if (flags->stack_b[0] > flags->stack_b[1])
		swap_b(flags);
}


static void	sort_to_four(t_flags *flags)
{
	int	i;
	int	j;

	i = 3;
	while (i > 0)
	{
		j = 0;
		while (j++ < i)
		{
			reverse_rotate_both(flags);
			try_swap(flags);
		}
		i--;
		j = 0;
		while (j++ < i)
		{
			rotate_both(flags);
			try_swap(flags);
		}
		i--;
	}
	while (i++ < 1)
		reverse_rotate_both(flags);
}

void	start_sort(t_flags *flags)
{
	int	i;

	i = 0;
	while (i <= flags->elements_total / 2 - 4)
	{
		push_group_b(flags);
		i += 4;
	}
	while (flags->element_count <= flags->elements_total - 8)
	{
		sort_to_four(flags);
		flags->element_count += 8;
	}
	rotate_both(flags);
}
