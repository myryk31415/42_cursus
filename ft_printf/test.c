/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:03:17 by padam             #+#    #+#             */
/*   Updated: 2023/10/18 18:26:23 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "limits.h"

#define TEXT "(% .d)\n", 0
// #define TEXT "%p\n", NULL

int	main()
{
	// char	*input	= "%s, integer: %p\n";
	// char	*str	= "hey";
	// int		i		= -12;

	int k = ft_printf(TEXT);
	int j = printf(TEXT);
	printf("%i, %i\n", k, j);
}
