# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/26 20:55:40 by mregrag           #+#    #+#              #
#    Updated: 2024/12/06 16:48:06 by mregrag          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = g++-10
CFLAGS	= -Wall -Wextra -Werror -std=c++98 -fsanitize=address
NAME	= losers
RM 	= rm -f

SRCS	= main.cpp FileReplace.cpp
OBJS	= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean
