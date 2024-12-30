# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/28 23:17:04 by mregrag           #+#    #+#              #
#    Updated: 2024/12/13 17:53:23 by mregrag          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = materia

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp AMateria.cpp Ice.cpp Cure.cpp Character.cpp MateriaSource.cpp

HEADERS = AMateria.hpp Cure.hpp Ice.hpp ICharacter.hpp Character.hpp MateriaSource.hpp IMateriaSource.hpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

