/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:26:04 by padam             #+#    #+#             */
/*   Updated: 2023/10/13 21:53:46 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	*ctop(char c)
{
	void	*ptr;

	ptr = malloc(sizeof(char));
	if (!ptr)
		return (NULL);
	*(char *)ptr = c;
	return (ptr);
}

void	print_content(void *ptr)
{
	ft_putchar_fd(*(char *)ptr, 1);
}
