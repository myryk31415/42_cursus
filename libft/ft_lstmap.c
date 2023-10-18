/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:02:50 by padam             #+#    #+#             */
/*   Updated: 2023/10/14 12:32:39 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_listchar	*ft_lstmap(t_listchar *lst, void *(*f)(void *), void (*del)(void *))
{
	t_listchar	*new_list;
	t_listchar	*new_element;
	void	*cont_temp;

	new_list = NULL;
	while (lst)
	{
		cont_temp = f(lst->content);
		new_element = ft_lstnew(cont_temp);
		if (!new_element)
		{
			ft_lstclear(&new_list, del);
			del(cont_temp);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_element);
		lst = lst->next;
	}
	return (new_list);
}
