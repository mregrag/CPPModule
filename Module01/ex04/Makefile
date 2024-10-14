# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/10 17:44:05 by mregrag           #+#    #+#              #
#    Updated: 2024/10/14 05:04:25 by mregrag          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
NAME	= replace
RM 	= rm -f

SRCS	= main.cpp Replace.cpp
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

.PHONY: all clean fclean re
