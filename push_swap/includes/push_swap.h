/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42heilbronn.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:16:46 by padam             #+#    #+#             */
/*   Updated: 2023/11/24 16:25:39 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

typedef struct s_flags
{
	int	*stack_a;
	int	*stack_b;
}t_flags;

//utils
void	stop_program(char *message, t_flags *flags);
int		check_args(int argc, char **argv);
int		fill_stack(t_flags *flags, int argc, char **argv);

#endif
