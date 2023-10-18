/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:43:37 by padam             #+#    #+#             */
/*   Updated: 2023/10/14 12:32:39 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_listchar **lst, void (*del)(void*))
{
	if (*lst)
	{
		if ((*lst)->next)
			ft_lstclear(&((*lst)->next), *del);
		(*del)((*lst)->content);
		free(*lst);
	}
	*lst = NULL;
}
