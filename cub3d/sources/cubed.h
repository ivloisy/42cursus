/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:13:23 by ivloisy           #+#    #+#             */
/*   Updated: 2021/02/03 13:13:25 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBED_H
# define CUBED_H

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include "./get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include <math.h>

typedef struct	s_rgb
{
	int		r;
	int		g;
	int		b;
}				t_rgb;

typedef struct	s_tex
{
	void	*ptr;
	int		*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		w;
	int		h;
}				t_tex;

typedef struct	s_img
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		w;
	int		h;
}				t_img;

typedef struct	s_vec
{
	double	x;
	double	y;
}				t_vec;

typedef struct	s_plr
{
	double	x;
	double	y;
	t_vec	dir;
	t_vec	plan;
}				t_plr;

typedef struct	s_ray
{
	double	cam;
	t_vec	dir;
	t_vec	pos;
	int		map_x;
	int		map_y;
	int		side;
	t_vec	d;
	t_vec	s;
	int		stepx;
	int		stepy;
	int		hit;
	double	dist;
	int		height;
	int		start;
	int		end;
	int		tex_w;
	int		tex_h;
	int		tex_x;
	int		tex_y;
	double	stp;
	double	tex_pos;
	char	cardinal;
}				t_ray;

typedef struct	s_cub
{
	void	*ptr;
	void	*win;
	int		error;
	int		h;
	int		w;
	int		r;
	int		save;
	int		xs;
	t_vec	*sprite;
	int		sky;
	t_tex	tex_sky;
	char	*no_p;
	int		no;
	t_tex	*tex_no;
	char	*so_p;
	int		so;
	t_tex	*tex_so;
	char	*we_p;
	int		we;
	t_tex	*tex_we;
	char	*ea_p;
	int		ea;
	t_tex	*tex_ea;
	char	*s_p;
	int		s;
	t_tex	*tex_s;
	t_rgb	f_c;
	int		f_color;
	int		f;
	t_tex	*tex_f;
	t_rgb	c_c;
	int		c_color;
	int		c;
	t_tex	*tex_c;
	t_tex	*tex_sb;
	int		m;
	int		m_x;
	int		m_y;
	char	**map;
	int		player;
	int		pos_dir;
	t_plr	plr;
	t_img	*img;
	int		forward;
	int		back;
	int		left;
	int		right;
	int		rotatel;
	int		rotater;
	double	spr_pos_x;
	double	spr_pos_y;
	double	trs_x;
	double	trs_y;
	int		spr_scr_x;
	int		s_h;
	int		s_w;
	int		s_start_x;
	int		s_end_x;
	int		s_start_y;
	int		s_end_y;
	int		*s_order;
	double	*s_dist;
	int		s_x;
	int		s_y;
	t_ray	ray;
}				t_cub;

typedef struct	s_save
{
	int		fd;
	int		size;
	int		pix;
}				t_save;

typedef enum	e_error
{
	NO_ERROR,
	SUCCESS,
	BASIC_ERROR,
	NB_ARG_ERROR,
	FILE_TYPE_ERROR,
	FLAG_ERROR,
	NOT_VALID_FILE_ERROR,
	NOT_VALID_R_ERROR,
	NOT_VALID_NO_ERROR,
	NOT_VALID_SO_ERROR,
	NOT_VALID_WE_ERROR,
	NOT_VALID_EA_ERROR,
	NOT_VALID_S_ERROR,
	NOT_VALID_F_ERROR,
	NOT_VALID_F_C_ERROR,
	NOT_VALID_F_P_ERROR,
	NOT_VALID_C_ERROR,
	NOT_VALID_C_C_ERROR,
	NOT_VALID_C_P_ERROR,
	NOT_VALID_M_ERROR,
	NB_PLAY_ERROR,
	MLX_ERROR,
	IMG_ERROR,
	TEX_ERROR,
	TEX_F_ERROR,
	TEX_C_ERROR,
	READ_ERROR
}				t_error;

int				get_next_line(int fd, char **line);
void			exit_error(t_cub *cub);
int				ft_close(int keycode, t_cub cub);

int				is_r(char *line, t_cub *cub);
int				is_no(char *line, t_cub *cub);
int				is_so(char *line, t_cub *cub);
int				is_we(char *line, t_cub *cub);
int				is_ea(char *line, t_cub *cub);
int				is_s(char *line, t_cub *cub);
int				is_f(char *line, t_cub *cub);
int				is_c(char *line, t_cub *cub);
int				is_m(char *line, t_cub *cub);
int				path_good_c(int c);
int				color_good_c(int c);
int				map_good_c(int c);
int				check_map(t_cub *cub);

int				launch(t_cub *cub);
int				get_tex(t_cub *cub);
void			move(t_cub *cub);
void			move_f(t_cub *cub, double speed);
void			move_b(t_cub *cub, double speed);
void			move_l(t_cub *cub, double speed);
void			move_r(t_cub *cub, double speed);
int				display(t_cub *cub);
int				save(t_cub *cub);
void			ft_pixel_put(t_img *img, int x, int y, int color);

t_img			*new_image(t_cub *cub, int w, int h);
t_tex			*new_texture(t_cub *cub, char *path);
void			free_img(t_cub *cub, t_img *img);
void			raycasting(t_cub *cub, int x);
void			get_cardinal(t_cub *cub);
int				draw_sprites(t_cub *cub, double *z);

int				get_rgb(t_rgb *rgb);
int				get_a(int rgb);
int				get_r(int rgb);
int				get_g(int rgb);
int				get_b(int rgb);

#endif
