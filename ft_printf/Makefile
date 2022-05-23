# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/10 00:25:55 by ivloisy           #+#    #+#              #
#    Updated: 2020/04/10 00:26:04 by ivloisy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCDIR = sources

INCDIR = includes

OBJDIR = objects

CC = gcc

FLAG = -I -g -Wall -Werror -Wextra

SRC = $(wildcard $(SRCDIR)/*.c)

OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

HDR = ft_printf.h

LIBHDR = $(wildcard $(INCDIR)/*.h)

FCT = ft_printf.c

FOBJ = $(FCT:%.c=$(OBJDIR)/%.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(FOBJ)
	@ar rc $(NAME) $(OBJ) $(FOBJ)
	@ranlib $(NAME)
	@echo "\033[36m--------------------------------------------------------------------------------\n$@ has been created !\n--------------------------------------------------------------------------------\033[0m"

$(OBJ): $(OBJDIR)/%.o: $(SRCDIR)/%.c $(HDR) $(LIBHDR) | $(OBJDIR)
	@echo "\033[32m$<\t\t--->\t\t$@\033[0m"
	@$(CC) $(FLAG) -o $@ -c $<

$(FOBJ): $(FCT) $(HDR) $(LIBHDR) $(OBJDIR)
	@echo "\033[32m$(FCT)\t\t\t--->\t\t$(FOBJ)\033[0m"
	@$(CC) $(FLAG) -o $@ -c $<

$(OBJDIR):
	@echo "\033[32m--------------------------------------------------------------------------------\nCompilation...\033[0m"
	@mkdir -p $(OBJDIR)

clean:
	@echo "\033[33m--------------------------------------------------------------------------------\nRemove $(OBJDIR) directory...\033[0m"
	@/bin/rm -rf $(OBJDIR)

fclean: clean
	@echo "\033[33m--------------------------------------------------------------------------------\nRemove $(NAME) file...\033[0m"
	@/bin/rm -f $(NAME)

re: fclean all
