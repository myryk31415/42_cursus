/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:03:17 by padam             #+#    #+#             */
/*   Updated: 2023/10/17 23:34:58 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "limits.h"

#define TEXT "%#5X, %#5X, %#5X, %#5X, %#5X, %#5X, %#5X, %#5X, %#5X, %#5X\n", 0, 5, -1, -10, 0x1234,-1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX
// #define TEXT "\001\002\007\v\010\f\r\n"

int	main()
{
	// char	*input	= "%s, integer: %p\n";
	// char	*str	= "hey";
	// int		i		= -12;

	int k = ft_printf(TEXT);
	int j = printf(TEXT);
	printf("%i, %i\n", k, j);
}
