# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/30 23:55:43 by mregrag           #+#    #+#              #
#    Updated: 2025/01/27 19:07:16 by mregrag          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = ex02

SRCS = main.cpp
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

# symbols: $(NAME)
# 	nm -C $(NAME) | grep "swap"

%.o: %.cpp Array.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

