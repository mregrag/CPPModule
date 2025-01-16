# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/30 23:52:41 by mregrag           #+#    #+#              #
#    Updated: 2025/01/08 21:46:30 by mregrag          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = iter

SRCS = main.cpp
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)


symbols: $(NAME)
	nm -C $(NAME) | grep "swap"

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

