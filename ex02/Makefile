# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atamas <atamas@student.42wolfsburg.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/16 10:48:23 by atamas            #+#    #+#              #
#    Updated: 2024/10/16 16:56:46 by atamas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bankster
SRC = Account.cpp tests.cpp
OBJ = $(SRC:.cpp=.o)
CXXFLAGS = -Wall -Werror -Wextra
CXX = c++

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all fclean clean re