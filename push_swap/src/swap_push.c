/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42heilbronn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:53:57 by padam             #+#    #+#             */
/*   Updated: 2023/11/27 15:31:42 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//swaps the first two elements at the top of stack a
void	swap_a(t_flags *flags)
{
	int	tmp;

	if (flags->size_a < 2)
		stop_program("Not enough elements in stack A", flags);
	tmp = flags->stack_a[0];
	flags->stack_a[0] = flags->stack_a[1];
	flags->stack_a[1] = tmp;
	ft_printf("sa\n");
}

//swaps the first two elements at the top of stack b
void	swap_b(t_flags *flags)
{
	int	tmp;

	if (flags->size_b < 2)
		stop_program("Not enough elements in stack B", flags);
	tmp = flags->stack_b[0];
	flags->stack_b[0] = flags->stack_b[1];
	flags->stack_b[1] = tmp;
	ft_printf("sb\n");
}

//swaps the first two elements at the top of both stacks
void	swap_both(t_flags *flags)
{
	int	tmp;

	if (flags->size_b < 2)
		stop_program("Not enough elements in stack B", flags);
	tmp = flags->stack_b[0];
	flags->stack_b[0] = flags->stack_b[1];
	flags->stack_b[1] = tmp;
	if (flags->size_a < 2)
		stop_program("Not enough elements in stack A", flags);
	tmp = flags->stack_a[0];
	flags->stack_a[0] = flags->stack_a[1];
	flags->stack_a[1] = tmp;
	ft_printf("ss\n");
}

//pushes the first element of stack b to the top of stack a
void	push_a(t_flags *flags)
{
	int	i;

	if (flags->size_b == 0)
		stop_program("Stack B is empty", flags);
	i = flags->size_a;
	while (i > 0)
	{
		flags->stack_a[i] = flags->stack_a[i - 1];
		i--;
	}
	flags->stack_a[0] = flags->stack_b[0];
	i = 0;
	while (i < flags->size_b - 1)
	{
		flags->stack_b[i] = flags->stack_b[i + 1];
		i++;
	}
	flags->size_a++;
	flags->size_b--;
	ft_printf("pa\n");
}

//pushes the first element of stack a to the top of stack b
void	push_b(t_flags *flags)
{
	int	i;

	if (flags->size_a == 0)
		stop_program("Stack A is empty", flags);
	i = flags->size_b;
	while (i > 0)
	{
		flags->stack_b[i] = flags->stack_b[i - 1];
		i--;
	}
	flags->stack_b[0] = flags->stack_a[0];
	i = 0;
	while (i < flags->size_a - 1)
	{
		flags->stack_a[i] = flags->stack_a[i + 1];
		i++;
	}
	flags->size_b++;
	flags->size_a--;
	ft_printf("pb\n");
}
