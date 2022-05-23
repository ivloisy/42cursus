/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:13:34 by ivloisy           #+#    #+#             */
/*   Updated: 2021/02/03 13:13:35 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cubed.h"

static void	draw_ceil(t_cub *cub, int x)
{
	int		y;

	y = 0;
	while (y < cub->ray.start)
	{
		ft_pixel_put(cub->img, x, y, get_rgb(&(cub->c_c)));
		y++;
	}
}

static void	draw_floor(t_cub *cub, int x)
{
	int		y;

	y = cub->ray.end;
	while (y < cub->h)
	{
		ft_pixel_put(cub->img, x, y, get_rgb(&(cub->f_c)));
		y++;
	}
}

static void	draw_texture(t_cub *cub, int x)
{
	int		y;
	int		color;

	y = cub->ray.start;
	while (y < cub->ray.end)
	{
		cub->ray.tex_y = (int)cub->ray.tex_pos & (cub->ray.tex_h - 1);
		cub->ray.tex_pos += cub->ray.stp;
		if (cub->ray.cardinal == 'N')
			color = cub->tex_no->addr[cub->tex_no->w * cub->ray.tex_y
					+ cub->ray.tex_x];
		if (cub->ray.cardinal == 'S')
			color = cub->tex_so->addr[cub->tex_so->w * cub->ray.tex_y
					+ cub->ray.tex_x];
		if (cub->ray.cardinal == 'W')
			color = cub->tex_we->addr[cub->tex_we->w * cub->ray.tex_y
					+ cub->ray.tex_x];
		if (cub->ray.cardinal == 'E')
			color = cub->tex_ea->addr[cub->tex_ea->w * cub->ray.tex_y
					+ cub->ray.tex_x];
		ft_pixel_put(cub->img, x, y, color);
		y++;
	}
}

static void	draw_wall(t_cub *cub, double *z)
{
	int		x;

	x = 0;
	while (x < cub->w)
	{
		raycasting(cub, x);
		if (cub->c_color == 1)
			draw_ceil(cub, x);
		draw_texture(cub, x);
		if (cub->f_color == 1)
			draw_floor(cub, x);
		z[x] = cub->ray.dist;
		x++;
	}
}

int			display(t_cub *cub)
{
	double	z[cub->w];

	free_img(cub, cub->img);
	if ((cub->img = new_image(cub, cub->w, cub->h)) == NULL)
	{
		cub->error = IMG_ERROR;
		return (cub->error);
	}
	move(cub);
	draw_wall(cub, z);
	if (draw_sprites(cub, z) != SUCCESS)
		return (cub->error);
	return (SUCCESS);
}
