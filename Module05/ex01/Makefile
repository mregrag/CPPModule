# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/14 14:21:00 by mregrag           #+#    #+#              #
#    Updated: 2025/01/19 16:45:22 by mregrag          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= bureaucrat

CC	= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98

SRC	= main.cpp Bureaucrat.cpp Form.cpp

HPP	= Bureaucrat.hpp Form.hpp

OBJ	= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp $(HPP)
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
