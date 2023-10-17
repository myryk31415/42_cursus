/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: padam <padam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:03:17 by padam             #+#    #+#             */
/*   Updated: 2023/10/17 17:02:30 by padam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "limits.h"

#define TEXT "{%%}\n"
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
