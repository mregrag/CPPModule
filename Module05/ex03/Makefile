# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/29 20:05:44 by mregrag           #+#    #+#              #
#    Updated: 2025/01/19 17:48:35 by mregrag          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= bureaucrat

CC	= c++
CFLAGS 	= -Wall -Wextra -Werror -std=c++98

SRC	= main.cpp \
	  Bureaucrat.cpp\
	  AForm.cpp \
	  PresidentialPardonForm.cpp \
	  RobotomyRequestForm.cpp \
	  ShrubberyCreationForm.cpp \
	  Intern.cpp

HPP = Bureaucrat.hpp \
      AForm.hpp \
      PresidentialPardonForm.hpp \
      RobotomyRequestForm.hpp \
      ShrubberyCreationForm.hpp

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

