/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42heilbronn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:12:10 by padam             #+#    #+#             */
/*   Updated: 2023/11/24 16:26:46 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stop_program(char *message, t_flags *flags)
{
	ft_printf("----------------------------------------\n");
	ft_printf("Program stopped - ");
	ft_printf("%s\n", message);
	ft_printf("----------------------------------------\n");
	if (flags->stack_a)
		free(flags->stack_a);
	if (flags->stack_b)
		free(flags->stack_b);
}

static void	print_error(void)
{
	ft_printf("\
----------------------------------------\n\
Formatting error!\n\
Please enter a list of integers.\n\
Example: ./push_swap 12 -2 0 32 +5\n\
----------------------------------------\n\
");
}

int	check_args(int argc, char **argv)
{
	if (argc == 1)
	{
		print_error();
		return (0);
	}
	while (--argc)
	{
		if (!ft_isnumber(argv[argc]))
		{
			print_error();
			return (0);
		}
	}
	return (1);
}

int	fill_stack(t_flags *flags, int argc, char **argv)
{
	int	i;

	i = 0;
	flags->stack_a = (int *)malloc(sizeof(int) * (argc - 1));
	flags->stack_b = (int *)malloc(sizeof(int) * (argc - 1));
	if (!flags->stack_a || !flags->stack_b)
		return (0);
	while (--argc)
		flags->stack_a[i++] = ft_atoi(argv[argc]);
	return (1);
}
