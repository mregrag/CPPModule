# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 20:58:37 by mregrag           #+#    #+#              #
#    Updated: 2024/11/26 18:50:57 by mregrag          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC     = c++
CFLAGS =  -Wall -Wextra -Werror -std=c++98 -Wshadow -g
NAME   = scavtrap
RM     = rm -f

SRCS   = main.cpp ClapTrap.cpp ScavTrap.cpp
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
