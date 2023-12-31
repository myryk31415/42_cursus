/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42heilbronn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:16:46 by padam             #+#    #+#             */
/*   Updated: 2023/12/18 18:37:49 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <stdio.h>

typedef struct s_flags
{
	int	*stack_a;
	int	size_a;
	int	*stack_b;
	int	size_b;

	int	group_size;
	int	elements_total;
	int	element_count;
	int	b_rotated;
}t_flags;

//test
// void	test_operations(t_flags	*t_flags);
// void	print_stacks(t_flags *flags);
//merge
void	merge_to_a(t_flags *flags);

//utils
void	push_b_half(t_flags *flags);
void	stop_program(t_flags *flags);
int		check_args(int argc, char **argv);
int		fill_stack(t_flags *flags, int argc, char **argv);
int		is_sorted(t_flags *flags);

//start_sort
void	start_sort(t_flags *flags);
void	sort_small(t_flags *flags);

//merge_to_stack
void	merge_to_a(t_flags *flags);
void	merge_to_b(t_flags *flags);
int		push_to_a(int b_rotated, t_flags *flags);

//operations
void	swap_a(t_flags *flags);
void	swap_b(t_flags *flags);
void	swap_both(t_flags *flags);
void	push_a(t_flags *flags);
void	push_b(t_flags *flags);
void	rotate_a(t_flags *flags);
void	rotate_b(t_flags *flags);
void	rotate_both(t_flags *flags);
void	reverse_rotate_a(t_flags *flags);
void	reverse_rotate_b(t_flags *flags);
void	reverse_rotate_both(t_flags *flags);

#endif
