/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:24:35 by padam             #+#    #+#             */
/*   Updated: 2023/10/13 22:54:18 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

t_list	*character(int c)
{
	void	*cont;

	cont = ctop(c);
	if (!cont)
		return (NULL);
	return (ft_lstnew(cont));
}

t_list	*string(char *str)
{
	t_list	**lst;
	t_list	*new;
	void	*cont;

	lst = NULL;
	while (*str)
	{
		cont = ctop(*str++);
		new = ft_lstnew(cont);
		if (!new || !cont)
		{
			ft_lstclear(lst, free);
			free (cont);
			return (NULL);
		}
		ft_lstadd_back(lst, new);
	}
	return (*lst);
}

t_list	*pointer(void *ptr)
{
	ptr = NULL;
	return (0);
}

t_list	*integer(long integer)
{
	integer = 0;
	return (0);
}
