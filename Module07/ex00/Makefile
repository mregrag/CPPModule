# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/30 23:48:51 by mregrag           #+#    #+#              #
#    Updated: 2025/01/08 21:39:10 by mregrag          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = whatever
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98  -g

SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

symbols: $(NAME)
	nm -C $(NAME) | grep "swap"

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

