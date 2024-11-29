# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 20:58:37 by mregrag           #+#    #+#              #
#    Updated: 2024/11/26 19:48:16 by mregrag          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC     = c++
CFLAGS = -Wall -Wextra -Werror -Wshadow -std=c++98 -g
NAME   = fragtrap
RM     = rm -f

SRCS   = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
OBJS   = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp ClapTrap.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
