# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivloisy <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/15 02:59:11 by ivloisy           #+#    #+#              #
#    Updated: 2019/11/14 22:13:11 by ivloisy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CMPL = gcc -g -Wall -Werror -Wextra

SRC =	ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strlen.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c

BON =	ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c

OBJ = $(SRC:.c=.o)

OBB = $(BON:.c=.o)

$(NAME) :
	$(CMPL) -c $(SRC) -I.
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

all: $(NAME)

bonus:
	$(CMPL) -c $(BON) -I.
	ar rc $(NAME) $(OBB)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ) $(OBB)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

rb: re bonus
