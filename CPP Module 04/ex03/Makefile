# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/31 12:03:12 by ivloisy           #+#    #+#              #
#    Updated: 2022/01/26 18:25:55 by ivloisy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Interface

CC = c++

FLAG = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp AMateria.cpp Ice.cpp Cure.cpp Character.cpp MateriaSource.cpp

HDR = AMateria.hpp Ice.hpp Cure.hpp ICharacter.hpp Character.hpp IMateriaSource.hpp MateriaSource.hpp

OBJ = $(OBJDIR)/*.o

OBJDIR = objects

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[36m\n$@ creation\t\t\t\t🛠\n"
	$(CC) $(FLAG) -o $@ $+
	@echo "\033[35m\n$@ has been created with success !\t🌈\n"

$(OBJ): $(SRC) $(HDR)
	@echo "\033[32m\nSources files compilation\t\t\t⚙️\n"
	$(CC) $(FLAG) -c $(SRC)
	mkdir -p $(OBJDIR)
	mv *.o $(OBJDIR)

clean:
	@echo "\033[33m\nRemove objects files\t\t--->\t\t🗑\n"
	/bin/rm -rf $(OBJDIR)

fclean: clean
	@echo "\033[33m\nRemove $(NAME) file\t\t--->\t\t🗑\n"
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
