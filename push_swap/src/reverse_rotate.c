/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42heilbronn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:25:49 by padam             #+#    #+#             */
/*   Updated: 2023/12/17 14:15:58 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//reverses rotate the stack a by one, the last element becomes the first one
void	reverse_rotate_a(t_flags *flags)
{
	int	tmp;
	int	i;

	if (flags->size_a < 2)
		return ;
	tmp = flags->stack_a[flags->size_a - 1];
	i = flags->size_a - 1;
	while (i > 0)
	{
		flags->stack_a[i] = flags->stack_a[i - 1];
		i--;
	}
	flags->stack_a[0] = tmp;
	ft_printf("rra\n");
}

//reverses rotate the stack b by one, the last element becomes the first one
void	reverse_rotate_b(t_flags *flags)
{
	int	tmp;
	int	i;

	if (flags->size_b < 2)
		return ;
	tmp = flags->stack_b[flags->size_b - 1];
	i = flags->size_b - 1;
	while (i > 0)
	{
		flags->stack_b[i] = flags->stack_b[i - 1];
		i--;
	}
	flags->stack_b[0] = tmp;
	ft_printf("rrb\n");
}

void	reverse_rotate_a_no_output(t_flags *flags)
{
	int	tmp;
	int	i;

	if (flags->size_a < 2)
		return ;
	tmp = flags->stack_a[flags->size_a - 1];
	i = flags->size_a - 1;
	while (i > 0)
	{
		flags->stack_a[i] = flags->stack_a[i - 1];
		i--;
	}
	flags->stack_a[0] = tmp;
}

//reverses rotate both stacks by one, the last element becomes the first one
void	reverse_rotate_both(t_flags *flags)
{
	int	tmp;
	int	i;

	if (flags->size_a < 2 && flags->size_b < 2)
		return ;
	ft_printf("rrr\n");
	reverse_rotate_a_no_output(flags);
	if (flags->size_b < 2)
		return ;
	tmp = flags->stack_b[flags->size_b - 1];
	i = flags->size_b - 1;
	while (i > 0)
	{
		flags->stack_b[i] = flags->stack_b[i - 1];
		i--;
	}
	flags->stack_b[0] = tmp;
}
