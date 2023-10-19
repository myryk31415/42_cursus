/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 23:50:21 by padam             #+#    #+#             */
/*   Updated: 2023/10/18 17:28:08 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_lstchariter(t_listchar *lst, void (*f)(unsigned char*,
			t_flags *flags), t_flags *flags)
{
	int	i;

	i = 0;
	while (lst && !flags->error)
	{
		(*f)(&lst->content, flags);
		lst = lst->next;
	}
}

int	ft_lstcharsize(t_listchar *lst)
{
	int	i;

	i = 1;
	if (!lst)
		return (0);
	while (lst->next)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
