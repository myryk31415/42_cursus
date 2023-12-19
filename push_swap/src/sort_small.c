/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42heilbronn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:31:31 by padam             #+#    #+#             */
/*   Updated: 2023/12/18 18:39:01 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_flags *flags)
{
	int	i;

	i = 2;
	while (i--)
	{
		if (flags->stack_a[0] > flags->stack_a[1])
		{
			if (flags->stack_a[1] > flags->stack_a[2])
				swap_a(flags);
			else if (flags->stack_a[0] > flags->stack_a[2])
				rotate_a(flags);
			else
				swap_a(flags);
		}
		else if (flags->stack_a[1] > flags->stack_a[2])
		{
			if (flags->stack_a[0] > flags->stack_a[2])
				reverse_rotate_a(flags);
			else
				swap_a(flags);
		}
	}
}

static void	sort_five(t_flags *flags)
{
	flags->group_size = 3;
	push_b(flags);
	push_b(flags);
	if (flags->stack_b[0] > flags->stack_b[1])
		swap_b(flags);
	sort_three(flags);
	merge_to_a(flags);
}

void	sort_small(t_flags *flags)
{
	if (flags->size_a == 2 && flags->stack_a[0] > flags->stack_a[1])
		swap_a(flags);
	else if (flags->size_a == 3)
		sort_three(flags);
	else if (flags->size_a == 5)
		sort_five(flags);
}
