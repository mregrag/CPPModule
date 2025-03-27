# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/01 21:08:39 by mregrag           #+#    #+#              #
#    Updated: 2024/11/18 20:55:32 by mregrag          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= c++
NAME	= fixed
RM 	= rm -f

CFLAGS	= -Wall -Wextra -Werror -std=c++98 -g

SRCS	= main.cpp Fixed.cpp
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
