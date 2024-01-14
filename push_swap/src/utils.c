/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42heilbronn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:12:10 by padam             #+#    #+#             */
/*   Updated: 2024/01/14 15:08:12 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	test_operations(t_flags	*t_flags)
// {
// 	push_b(t_flags);
// 	push_b(t_flags);
// 	push_b(t_flags);
// 	swap_a(t_flags);
// 	swap_b(t_flags);
// 	swap_both(t_flags);
// 	push_a(t_flags);
// 	push_b(t_flags);
// 	rotate_a(t_flags);
// 	rotate_b(t_flags);
// 	rotate_both(t_flags);
// 	reverse_rotate_a(t_flags);
// 	reverse_rotate_b(t_flags);
// 	reverse_rotate_both(t_flags);
// }

// void	print_stacks(t_flags *flags)
// {
// 	int	i;

// 	i = 0;
// 	ft_printf("Stack A: ");
// 	while (i < flags->size_a)
// 		ft_printf("%d ", flags->stack_a[i++]);
// 	ft_printf("\n");
// 	i = 0;
// 	ft_printf("Stack B: ");
// 	while (i < flags->size_b)
// 		ft_printf("%d ", flags->stack_b[i++]);
// 	ft_printf("\n");
// }

void	push_b_half(t_flags *flags)
{
	int	i;
	int	groups;

	groups = flags->elements_total / flags->group_size;
	i = groups / 2;
	i *= flags->group_size;
	if (groups % 2)
		i += flags->elements_total % flags->group_size;
	while (i--)
		push_b(flags);
}

int	is_sorted(t_flags *flags)
{
	int	i;

	i = 0;
	if (flags->size_b)
		return (0);
	while (i < flags->size_a - 1)
	{
		if (flags->stack_a[i] > flags->stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	stop_program(t_flags *flags)
{
	ft_printf("Error\n");
	if (flags->stack_a)
		free(flags->stack_a);
	if (flags->stack_b)
		free(flags->stack_b);
	exit(1);
}

int	check_args(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	while (--argc)
	{
		if (!ft_isint(argv[argc]))
			return (0);
	}
	return (1);
}

int	fill_stack(t_flags *flags, int argc, char **argv)
{
	int		i;
	int		j;

	i = 0;
	flags->stack_a = (int *)malloc(sizeof(int) * (argc - 1));
	flags->stack_b = (int *)malloc(sizeof(int) * (argc - 1));
	if (!flags->stack_a || !flags->stack_b)
		return (0);
	while (--argc)
	{
		flags->stack_a[i] = ft_atoi(argv[i + 1]);
		j = 0;
		while (j < i)
		{
			if (flags->stack_a[j] == flags->stack_a[i])
				return (0);
			j++;
		}
		i++;
	}
	flags->size_a = i;
	flags->size_b = 0;
	return (1);
}
