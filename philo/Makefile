# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: padam <padam@student.42heilbronn.com>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 15:34:56 by padam             #+#    #+#              #
#    Updated: 2024/05/02 12:47:14 by padam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
CFLAGS = -g -pthread -Wall -Wextra -Werror $(INCLUDES)
INCLUDES = -I./includes

SRC_PATH = src
OBJ_PATH = obj

SRCS = libft_utils.c main.c philo_actions.c philosopher.c utils.c utils2.c
OBJ_NAME = $(SRCS:.c=.o)
OBJS = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJS)

$(OBJ_PATH)	:
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	printf "%-50s\r" "$(CC) $@"
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: all

.PHONY: all, $(OBJ_PATH), clean, fclean, re, bonus
