# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/26 22:23:46 by mregrag           #+#    #+#              #
#    Updated: 2024/12/06 17:01:17 by mregrag          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= g++-10
CFLAGS	= -Wall -Wextra -Werror -std=c++98
NAME	= harl
RM 	= rm -f

SRCS	= main.cpp Harl.cpp
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

