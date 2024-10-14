# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/09 23:39:03 by mregrag           #+#    #+#              #
#    Updated: 2024/10/10 15:43:34 by mregrag          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
NAME	= brain
RM 	= rm -f

SRCS	= main.cpp
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



