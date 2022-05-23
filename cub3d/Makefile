NAME = cub3D

CC = clang

FLAG = -g -Wall -Werror -Wextra

SRC = ./sources/cardinal.c \
		./sources/check_map.c \
		./sources/cub3d.c \
		./sources/display.c \
		./sources/exit_error.c \
		./sources/ft_close.c \
		./sources/ft_pixel_put.c \
		./sources/get_argb.c \
		./sources/get_map.c \
		./sources/get_next_line.c \
		./sources/good_c.c \
		./sources/image.c \
		./sources/is_c.c \
		./sources/is_f.c \
		./sources/is_m.c \
		./sources/is_r.c \
		./sources/is_tex.c \
		./sources/launch.c \
		./sources/move_fblr.c \
		./sources/move.c \
		./sources/save.c \
		./sources/sprites.c \
		./sources/wall.c 

BON = ./bonus/add_shade_bonus.c \
		./bonus/cardinal_bonus.c \
		./bonus/check_map_bonus.c \
		./bonus/cub3d_bonus.c \
		./bonus/display_bonus.c \
		./bonus/exit_error_bonus.c \
		./bonus/ft_close_bonus.c \
		./bonus/ft_pixel_put_bonus.c \
		./bonus/get_argb_bonus.c \
		./bonus/get_map_bonus.c \
		./bonus/get_next_line_bonus.c \
		./bonus/good_c_bonus.c \
		./bonus/image_bonus.c \
		./bonus/is_c_bonus.c \
		./bonus/is_f_bonus.c \
		./bonus/is_m_bonus.c \
		./bonus/is_r_bonus.c \
		./bonus/is_tex_bonus.c \
		./bonus/launch_bonus.c \
		./bonus/minimap_bonus.c \
		./bonus/mir_bonus.c \
		./bonus/move_fblr_bonus.c \
		./bonus/move_bonus.c \
		./bonus/save_bonus.c \
		./bonus/sprites_bonus.c \
		./bonus/wall_bonus.c

HDR = ./sources/cubed.h \
		./sources/get_next_line.h

HDRBONUS = ./bonus/cubed_bonus.h \
		./bonus/get_next_line_bonus.h

OBJ = $(SRC:.c=.o)

OBJBONUS = $(BON:.c=.o)

LFT = libft/libft.a

all: libft minilibx $(NAME)

bonus: fclean libft minilibx $(OBJBONUS)
	$(CC) $(FLAG) -o $(NAME) $(OBJBONUS) $(LFT) -Lminilibx/ -lX11 -lXext -lm -lbsd -lmlx

libft:
	make -C libft/

minilibx:
	make -C minilibx/

$(NAME): $(OBJ)
	$(CC) $(FLAG) -o $@ $^ $(LFT) -Lminilibx/ -lX11 -lXext -lm -lbsd -lmlx

$($(SRC)/%.o): $($(SRC)/%.c)
	$(CC) $(FLAG) -Iminilibx -o $@ -c $^

$($(BON)/%.o): $($(BON)/%.c)
	$(CC) $(FLAG) -Iminilibx -o $@ -c $^

$(OBJ): $(HDR)

$(OBJBONUS): $(HDRBONUS)

clean:
	rm -rf $(OBJ) $(OBJBONUS)
	make -C libft/ clean
	make -C minilibx/ clean

fclean: clean
	rm -f $(NAME) $(NAMEBONUS)
	rm -f ./cub3d.bmp ./cub3d_bonus.bmp
	make -C libft/ fclean
	make -C minilibx/ clean

re: fclean all

.PHONY: all clean fclean re bonus libft minilibx
