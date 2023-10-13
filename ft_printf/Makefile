# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: padam <padam@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 15:34:56 by padam             #+#    #+#              #
#    Updated: 2023/10/13 22:38:26 by padam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = ft_printf.c cases.c lst_functions.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror -I. -Ilibft
LIBFT_DIR = libft

all: $(NAME)

$(NAME): $(LIBFT_DIR)/libft.a $(OBJS)
	ar -rcs $(NAME) $(OBJS) $(LIBFT_DIR)/libft.a

libft/libft.a:
	make -C $(LIBFT_DIR)

%.o: %.c
	cc $(CFLAGS) -c $<

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all
