# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/05 19:25:55 by mregrag           #+#    #+#              #
#    Updated: 2024/10/05 22:10:08 by mregrag          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC	= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98
NAME	= megaphone
RM 	= rm -f

SRCS	= PhoneBook.cpp Contact.cpp main.cpp
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

