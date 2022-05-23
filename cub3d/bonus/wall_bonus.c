/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:12:35 by ivloisy           #+#    #+#             */
/*   Updated: 2021/02/03 13:12:36 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cubed_bonus.h"

static void	calc_distance(t_cub *cub)
{
	if (cub->ray.dir.x < 0)
	{
		cub->ray.stepx = -1;
		cub->ray.s.x = (cub->ray.pos.x - cub->ray.map_x) * cub->ray.d.x;
	}
	else
	{
		cub->ray.stepx = 1;
		cub->ray.s.x = (cub->ray.map_x + 1.0 - cub->ray.pos.x) * cub->ray.d.x;
	}
	if (cub->ray.dir.y < 0)
	{
		cub->ray.stepy = -1;
		cub->ray.s.y = (cub->ray.pos.y - cub->ray.map_y) * cub->ray.d.y;
	}
	else
	{
		cub->ray.stepy = 1;
		cub->ray.s.y = (cub->ray.map_y + 1.0 - cub->ray.pos.y) * cub->ray.d.y;
	}
}

static void	calc_hit(t_cub *cub)
{
	while (cub->ray.hit == 0)
	{
		if (cub->ray.s.x < cub->ray.s.y)
		{
			cub->ray.s.x += cub->ray.d.x;
			cub->ray.map_x += cub->ray.stepx;
			cub->ray.side = 0;
		}
		else
		{
			cub->ray.s.y += cub->ray.d.y;
			cub->ray.map_y += cub->ray.stepy;
			cub->ray.side = 1;
		}
		if (cub->map[cub->ray.map_y][cub->ray.map_x] != '0'
				&& cub->map[cub->ray.map_y][cub->ray.map_x] != '2'
				&& cub->map[cub->ray.map_y][cub->ray.map_x] != 'N'
				&& cub->map[cub->ray.map_y][cub->ray.map_x] != 'S'
				&& cub->map[cub->ray.map_y][cub->ray.map_x] != 'W'
				&& cub->map[cub->ray.map_y][cub->ray.map_x] != 'E')
			cub->ray.hit = 1;
	}
}

static void	start_end(t_cub *cub)
{
	get_cardinal(cub);
	if (cub->ray.side == 0)
		cub->ray.dist = fabs((cub->ray.map_x - cub->ray.pos.x
				+ (1 - cub->ray.stepx) / 2) / cub->ray.dir.x);
	else
		cub->ray.dist = fabs((cub->ray.map_y - cub->ray.pos.y
				+ (1 - cub->ray.stepy) / 2) / cub->ray.dir.y);
	cub->ray.height = fabs(cub->h / cub->ray.dist);
	cub->ray.start = (-1 * cub->ray.height) / 2 + cub->h / 2;
	if (cub->ray.start < 0)
		cub->ray.start = 0;
	cub->ray.end = cub->ray.height / 2 + cub->h / 2;
	if (cub->ray.end >= cub->h)
		cub->ray.end = cub->h - 1;
}

static void	calc_tex(t_cub *cub)
{
	double	wallx;

	if (cub->ray.side == 0)
		wallx = cub->ray.pos.y + cub->ray.dist * cub->ray.dir.y;
	else
		wallx = cub->ray.pos.x + cub->ray.dist * cub->ray.dir.x;
	wallx -= floor((wallx));
	cub->ray.tex_x = (int)(wallx * (double)(cub->ray.tex_w));
	if (cub->ray.side == 0 && cub->ray.dir.x > 0)
		cub->ray.tex_x = cub->ray.tex_w - cub->ray.tex_x - 1;
	if (cub->ray.side == 1 && cub->ray.dir.y < 0)
		cub->ray.tex_x = cub->ray.tex_w - cub->ray.tex_x - 1;
	cub->ray.stp = 1.0 * cub->ray.tex_h / cub->ray.height;
	cub->ray.tex_pos = (cub->ray.start - cub->h / 2 + cub->ray.height / 2)
			* cub->ray.stp;
}

void		raycasting(t_cub *cub, int x)
{
	cub->ray.cam = 2 * x / (double)cub->w - 1.0;
	cub->ray.pos.x = cub->plr.x;
	cub->ray.pos.y = cub->plr.y;
	cub->ray.dir.x = cub->plr.dir.x + cub->plr.plan.x * cub->ray.cam;
	cub->ray.dir.y = cub->plr.dir.y + cub->plr.plan.y * cub->ray.cam;
	cub->ray.map_x = (int)(cub->ray.pos.x);
	cub->ray.map_y = (int)(cub->ray.pos.y);
	cub->ray.d.x = sqrt(1 + pow(cub->ray.dir.y, 2) / pow(cub->ray.dir.x, 2));
	cub->ray.d.y = sqrt(1 + pow(cub->ray.dir.x, 2) / pow(cub->ray.dir.y, 2));
	cub->ray.hit = 0;
	calc_distance(cub);
	calc_hit(cub);
	start_end(cub);
	calc_tex(cub);
}
