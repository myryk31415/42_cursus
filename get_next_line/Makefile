# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: padam <padam@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 15:34:56 by padam             #+#    #+#              #
#    Updated: 2023/10/29 14:07:38 by padam            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a
SRCS = get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
BONUSSRCS = get_next_line_bonus.c get_next_line_utils_bonus.c
BONUSOBJS = $(BONUSSRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%.o: %.c
	cc $(CFLAGS) -c $<

clean:
	rm -f $(OBJS)
	rm -f $(BONUSOBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(BONUSOBJS)
	ar -rcs $(NAME) $(BONUSOBJS)
