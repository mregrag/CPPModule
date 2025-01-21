# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/05 19:25:40 by mregrag           #+#    #+#              #
#    Updated: 2025/01/17 15:45:07 by mregrag          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
NAME	= megaphone
SRCS	= megaphone.cpp
OBJS	= $(SRCS:.cpp=.o)
RM 	= rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

debug:
	gdb ./test
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean
