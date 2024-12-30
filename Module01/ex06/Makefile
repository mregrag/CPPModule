# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/26 22:41:18 by mregrag           #+#    #+#              #
#    Updated: 2024/12/06 17:39:56 by mregrag          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= gcc-10
CFLAGS	= -Wall -Wextra -Werror -std=c++98
NAME	= harlFilter
RM 	= rm -f

SRCS	= main.cpp Harl.cpp
OBJS	= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp Harl.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean

