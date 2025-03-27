# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mregrag <mregrag@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/02 16:52:00 by mregrag           #+#    #+#              #
#    Updated: 2024/11/18 20:55:53 by mregrag          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC     = c++
NAME   = bsq
RM     = rm -f
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS   = main.cpp Fixed.cpp Point.cpp bsq.cpp

OBJS   = $(SRCS:.cpp=.o)

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
