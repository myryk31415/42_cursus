/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:26:04 by padam             #+#    #+#             */
/*   Updated: 2023/10/15 21:54:38 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_toupperchar(unsigned char *c)
{
	if (*c >= 97 && *c <= 122)
		*c -= 32;
}

void	print_content(unsigned char *c)
{
	ft_putchar_fd(*c, 1);
}

t_listchar	*ft_lstcharnew(unsigned char c)
{
	t_listchar	*new_node;

	new_node = malloc(sizeof(t_listchar));
	if (!new_node)
		return (NULL);
	new_node->content = c;
	new_node->next = NULL;
	return (new_node);
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

t_listchar	*ft_lstcharlast(t_listchar *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	*ft_lstcharadd_back(t_listchar **lst, t_listchar *new)
{
	if (!new)
		return (NULL);
	if (*lst)
		ft_lstcharlast(*lst)->next = new;
	else
		*lst = new;
	return (*lst);
}

void	*ft_lstcharadd_front(t_listchar **lst, t_listchar *new)
{
	if (!new)
		return (NULL);
	new->next = *lst;
	*lst = new;
	return (*lst);
}

void	ft_lstchariter(t_listchar *lst, void (*f)(unsigned char*))
{
	while (lst)
	{
		(*f)(&lst->content);
		lst = lst->next;
	}
}

void	*ft_lstcharclear(t_listchar **lst)
{
	if (*lst)
	{
		if ((*lst)->next)
			ft_lstcharclear(&((*lst)->next));
		free(*lst);
	}
	*lst = NULL;
	return (NULL);
}
