# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/31 12:03:12 by ivloisy           #+#    #+#              #
#    Updated: 2022/02/11 04:37:44 by ivloisy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = MutantStack

CXX = c++

CXXFLAGS = -MMD -MP -Wall -Wextra -Werror -std=c++98

SRC = main.cpp

HDR = MutantStack.hpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[36m\n$@ creation\t\t\t\t🛠\n"
	$(CXX) $(CXXFLAGS) -o $@ $+
	@echo "\033[35m\n$@ has been created with success !\t🌈\n"

%.o: %.cpp
	@echo "\033[32m\nSources files compilation\t\t\t⚙️\n"
	$(CXX) $(CXXFLAGS) -c $(SRC)

clean:
	@echo "\033[33m\nRemove objects files\t\t--->\t\t🗑\n"
	/bin/rm -rf $(OBJ) *.d

fclean: clean
	@echo "\033[33m\nRemove $(NAME) file\t\t--->\t\t🗑\n"
	/bin/rm -f $(NAME)

-include $(OBJ:.o=.d)

re: fclean all

.PHONY: all clean fclean re
