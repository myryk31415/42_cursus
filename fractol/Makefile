# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: padam <padam@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 15:34:56 by padam             #+#    #+#              #
#    Updated: 2023/11/09 20:15:44 by padam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fract\'ol
SRCS = main.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBMLX_DIR = ./MLX42
HEADERS	:= -I $(LIBMLX_DIR)/include
LIBFT_DIR = libft
LIBMLX = $(LIBMLX_DIR)/build/libmlx42.a -ldl -lglfw -pthread -lm -framework Cocoa -framework OpenGL -framework IOKit

all: $(NAME)

$(NAME): $(LIBFT_DIR)/libft.a $(SRCS)
	$(CC) -o $(NAME) $(CFLAGS) $(SRCS) $(HEADERS) -L $(LIBFT_DIR) -lft $(LIBMLX)

$(LIBFT_DIR)/libft.a:
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all, $(LIBFT_DIR)/libft.a, clean, fclean, re, libmlx
