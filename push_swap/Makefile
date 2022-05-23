# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/11 16:17:21 by ivloisy           #+#    #+#              #
#    Updated: 2021/10/25 13:20:40 by ivloisy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

FLAG = -Wall -Werror -Wextra

SRCDIR = sources

SRC = ./$(SRCDIR)/push_swap.c \
		./$(SRCDIR)/parsing.c \
		./$(SRCDIR)/check_stack.c \
		./$(SRCDIR)/simplification.c \
		./$(SRCDIR)/sort.c \
		./$(SRCDIR)/swap.c \
		./$(SRCDIR)/push.c \
		./$(SRCDIR)/rotate.c \
		./$(SRCDIR)/reverse_rotate.c \
		./$(SRCDIR)/exit_error.c

HDR = ./sources/push_swap.h

OBJDIR = objects

OBJ = $(OBJDIR)/*.o

LFT = ./libft/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LFT)
	@echo "\033[36m\n$(NAME) creation\t\t\t\t🛠\n"
	$(CC) $(FLAG) -o $@ $+
	@echo "\033[35m\n$(NAME) has been created with success !\t🌈\n"

$(OBJ): $(SRC) $(HDR)
	@echo "\033[32m\nSources files compilation\t\t\t⚙️\n"
	$(CC) $(FLAG) -c $(SRC)
	mkdir -p $(OBJDIR)
	mv *.o $(OBJDIR)

$(LFT): ./libft/*.c ./libft/*.h
	make -C libft/
	make -C libft/ bonus
	make -C libft/ utils

clean:
	@echo "\033[33m\nRemove objects files\t\t--->\t\t🗑\n"
	rm -rf $(OBJDIR)
	make -C libft/ clean

fclean: clean
	@echo "\033[33m\nRemove $(NAME) file\t\t--->\t\t🗑\n"
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re
