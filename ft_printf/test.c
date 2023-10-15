/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:03:17 by padam             #+#    #+#             */
/*   Updated: 2023/10/15 23:17:38 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "limits.h"

#define TEXT "%.6i\n%.12i\n%.2i\n", 43, 3487, 541232

int	main()
{
	// char	*input	= "%s, integer: %p\n";
	// char	*str	= "hey";
	// int		i		= -12;

	int k = ft_printf(TEXT);
	int j = printf(TEXT);
	printf("%i\n", k - j);
}
