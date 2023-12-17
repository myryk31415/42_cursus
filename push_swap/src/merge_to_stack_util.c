/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_to_stack_util.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42heilbronn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 19:24:35 by padam             #+#    #+#             */
/*   Updated: 2023/12/17 19:25:04 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_to_a(int b_rotated, t_flags *flags)
{
	if (!b_rotated)
		reverse_rotate_b(flags);
	push_a(flags);
	return (0);
}
