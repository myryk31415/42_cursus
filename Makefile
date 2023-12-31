# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: padam <padam@student.42heilbronn.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 14:19:40 by padam             #+#    #+#              #
#    Updated: 2024/01/02 22:35:15 by padam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECTS=	fractol		ft_printf		get_next_line	\
			libft		minitalk		push_swap

clean:
	for PROJECT in $(PROJECTS); do \
		make fclean -C $$PROJECT; \
	done

.PHONY: clean
