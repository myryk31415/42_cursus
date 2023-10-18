/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:11:46 by padam             #+#    #+#             */
/*   Updated: 2023/10/14 12:32:39 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_listchar **lst, t_listchar *new)
{
	if (*lst)
	{
		ft_lstlast(*lst)->next = new;
	}
	else
		*lst = new;
}
