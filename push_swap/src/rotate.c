/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42heilbronn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:17:04 by padam             #+#    #+#             */
/*   Updated: 2023/11/29 20:05:36 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//rotates the stack a by one, the first element becomes the last one
void	rotate_a(t_flags *flags)
{
	int	tmp;
	int	i;

	if (flags->size_a < 2)
		return ;
	tmp = flags->stack_a[0];
	i = 0;
	while (i < flags->size_a - 1)
	{
		flags->stack_a[i] = flags->stack_a[i + 1];
		i++;
	}
	flags->stack_a[i] = tmp;
	ft_printf("ra\n");
}

//rotates the stack b by one, the first element becomes the last one
void	rotate_b(t_flags *flags)
{
	int	tmp;
	int	i;

	if (flags->size_b < 2)
		return ;
	tmp = flags->stack_b[0];
	i = 0;
	while (i < flags->size_b - 1)
	{
		flags->stack_b[i] = flags->stack_b[i + 1];
		i++;
	}
	flags->stack_b[i] = tmp;
	ft_printf("rb\n");
}

//rotates both stacks by one, the first element becomes the last one
void	rotate_both(t_flags *flags)
{
	int	tmp;
	int	i;

	if (flags->size_a < 2 && flags->size_b < 2)
		return ;
	tmp = flags->stack_a[0];
	i = 0;
	while (i < flags->size_a - 1)
	{
		flags->stack_a[i] = flags->stack_a[i + 1];
		i++;
	}
	flags->stack_a[i] = tmp;
	tmp = flags->stack_b[0];
	i = 0;
	while (i < flags->size_b - 1)
	{
		flags->stack_b[i] = flags->stack_b[i + 1];
		i++;
	}
	flags->stack_b[i] = tmp;
	ft_printf("rr\n");
}
