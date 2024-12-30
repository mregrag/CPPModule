# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/28 16:51:35 by mregrag           #+#    #+#              #
#    Updated: 2024/12/12 20:17:39 by mregrag          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = aanimal

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = AAnimal.cpp Dog.cpp Cat.cpp  Brain.cpp main.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp AAnimal.hpp Cat.hpp Dog.hpp Brain.hpp
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
