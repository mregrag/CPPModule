# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/29 21:33:58 by mregrag           #+#    #+#              #
#    Updated: 2025/01/22 22:56:43 by mregrag          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile
NAME = convert
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp ScalarConverter.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp ScalarConverter.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
