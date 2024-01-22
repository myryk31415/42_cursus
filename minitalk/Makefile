# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: padam <padam@student.42heilbronn.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 15:34:56 by padam             #+#    #+#              #
#    Updated: 2024/01/14 15:54:40 by padam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

CC = cc
CFLAGS = -Wall -Wextra -Werror -g $(INCLUDES)
INCLUDES = -I./includes
LIBFT_DIR = libft

SRC_PATH = src
OBJ_PATH = obj

SRCS_CLIENT = client.c
OBJ_NAME_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_CLIENT = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME_CLIENT))
SRCS_SERVER = server.c
OBJ_NAME_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_SERVER = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME_SERVER))

all: $(NAME)

$(NAME): client server

client: $(LIBFT_DIR)/libft.a $(OBJS_CLIENT)
	$(CC) -o client $(CFLAGS) $(OBJS_CLIENT) $(LIBFT_DIR)/libft.a

server: $(LIBFT_DIR)/libft.a $(OBJS_SERVER)
	$(CC) -o server $(CFLAGS) $(OBJS_SERVER) $(LIBFT_DIR)/libft.a

$(LIBFT_DIR)/libft.a:
	make -C $(LIBFT_DIR)

$(OBJ_PATH)	:
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	printf "%-50s\r" "$(CC) $@"
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ_PATH)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f server client
	make -C $(LIBFT_DIR) fclean

re: fclean all

bonus: all

.PHONY: all, $(LIBFT_DIR)/libft.a, $(OBJ_PATH), clean, fclean, re, bonus
