/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42heilbronn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:16:46 by padam             #+#    #+#             */
/*   Updated: 2023/11/29 13:19:04 by padam            ###   ########.fr       */
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
}t_flags;

//test
void	test_operations(t_flags	*t_flags);
void	print_stacks(t_flags *flags);

//utils
void	stop_program(char *message, t_flags *flags);
int		check_args(int argc, char **argv);
int		fill_stack(t_flags *flags, int argc, char **argv);

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
