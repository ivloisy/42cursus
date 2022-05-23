# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/31 12:03:12 by ivloisy           #+#    #+#              #
#    Updated: 2022/01/15 16:33:21 by ivloisy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Unnecessary_violence

CC = c++

FLAG = -Wall -Werror -Wextra

SRC = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

HDR = Weapon.hpp HumanA.hpp HumanB.hpp

OBJ = $(OBJDIR)/*.o

OBJDIR = objects

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[36m\n$@ creation\t\t\t\t🛠\n"
	$(CC) $(FLAG) -o $@ $+
	@echo "\033[35m\n$@ has been created with success !\t🌈\n"

$(OBJ): $(SRC) $(HDR)
	@echo "\033[32m\nSources files compilation\t\t\t\t⚙️\n"
	$(CC) $(FLAG) -c $(SRC)
	mkdir -p $(OBJDIR)
	mv *.o $(OBJDIR)

clean:
	@echo "\033[33m\nRemove objects files\t\t\t--->\t\t🗑\n"
	/bin/rm -rf $(OBJDIR)

fclean: clean
	@echo "\033[33m\nRemove $(NAME) file\t--->\t\t🗑\n"
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
