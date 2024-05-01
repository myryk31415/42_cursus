# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: padam <padam@student.42heilbronn.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 15:34:56 by padam             #+#    #+#              #
#    Updated: 2024/03/29 22:09:53 by padam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRCS = main.c utils.c utils2.c fractals.c hooks.c
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LIBMLX_DIR = ./MLX42
HEADERS	:= -I $(LIBMLX_DIR)/include -I.
LIBFT_DIR = ./libft
#MacOS
#LIBMLX = $(LIBMLX_DIR)/build/libmlx42.a -ldl -lglfw -pthread -lm -framework Cocoa -framework OpenGL -framework IOKit
#Linux
LIBMLX = $(LIBMLX_DIR)/build/libmlx42.a -lXext -lX11 -lm -lbsd -lglfw -lpthread

all: $(NAME)

$(NAME): $(LIBFT_DIR)/libft.a $(SRCS) $(LIBMLX_DIR)
	$(CC) -o $(NAME) $(CFLAGS) $(SRCS) $(HEADERS) -lft $(LIBMLX) -L $(LIBFT_DIR)

$(LIBFT_DIR)/libft.a:
	make -C $(LIBFT_DIR)

$(LIBMLX_DIR):
	git clone https://github.com/codam-coding-college/MLX42.git
	cd $(LIBMLX_DIR) && cmake -B build && cmake --build build -j4

clean:
	rm -f $(OBJS)
	rm -rf $(LIBMLX_DIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all, $(LIBFT_DIR)/libft.a, clean, fclean, re, libmlx
