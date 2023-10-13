/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:02:50 by padam             #+#    #+#             */
/*   Updated: 2023/10/11 16:39:31 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_element;
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
