/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:16:49 by ivloisy           #+#    #+#             */
/*   Updated: 2021/02/03 13:16:50 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cubed.h"

static void	sort_sprites(t_cub *cub)
{
	int		i;
	int		j;
	t_vec	tmp1;
	int		tmp2;

	i = 0;
	j = 1;
	while (j < cub->xs)
	{
		while (i < (cub->xs - 1))
		{
			if (cub->s_dist[i] < cub->s_dist[i + 1])
			{
				tmp1 = cub->sprite[i];
				cub->sprite[i] = cub->sprite[i + 1];
				cub->sprite[i + 1] = tmp1;
				tmp2 = cub->s_order[i];
				cub->s_order[i] = cub->s_order[i + 1];
				cub->s_order[i + 1] = tmp2;
			}
			i++;
		}
		j++;
	}
}

static void	init_sprites(t_cub *cub)
{
	int		i;

	i = 0;
	while (i < cub->xs)
	{
		cub->s_order[i] = i;
		cub->s_dist[i] = (pow((cub->plr.x - cub->sprite[i].x), 2)
				+ pow((cub->plr.y - cub->sprite[i].y), 2));
		i++;
	}
	sort_sprites(cub);
}

static void	init_matrix(t_cub *cub, int i)
{
	int inv;

	cub->spr_pos_x = cub->sprite[cub->s_order[i]].x - cub->ray.pos.x;
	cub->spr_pos_y = cub->sprite[cub->s_order[i]].y - cub->ray.pos.y;
	inv = 1.0 / (cub->plr.plan.x * cub->plr.dir.y
			- cub->plr.dir.x * cub->plr.plan.y);
	cub->trs_x = inv * (cub->plr.dir.y * cub->spr_pos_x
			- cub->plr.dir.x * cub->spr_pos_y);
	cub->trs_y = inv * (-cub->plr.plan.y * cub->spr_pos_x
			+ cub->plr.plan.x * cub->spr_pos_y);
	cub->spr_scr_x = (int)((cub->w / 2) * (1 + cub->trs_x / cub->trs_y));
	cub->s_h = abs((int)(cub->h / cub->trs_y)) * 0.7;
	cub->s_start_y = -cub->s_h / 2 + cub->h / 2;
	if (cub->s_start_y < 0)
		cub->s_start_y = 0;
	cub->s_end_y = cub->s_h / 2 + cub->h / 2;
	if (cub->s_end_y >= cub->h)
		cub->s_end_y = cub->h - 1;
	cub->s_w = abs((int)(cub->h / cub->trs_y)) * 0.7;
	cub->s_start_x = -cub->s_w / 2 + cub->spr_scr_x;
	if (cub->s_start_x < 0)
		cub->s_start_x = 0;
	cub->s_end_x = cub->s_w / 2 + cub->spr_scr_x;
	if (cub->s_end_x >= cub->w)
		cub->s_end_x = cub->w - 1;
}

static void	dis_px(t_cub *cub, int j, double *z, int i)
{
	int		y;
	int		d;
	int		col;

	y = cub->s_start_y;
	if (cub->trs_y > 0 && j > 0 && j < cub->w && sqrt(cub->s_dist[i]) < z[j])
	{
		while (y < cub->s_end_y)
		{
			d = y * 256 - cub->h * 128 + cub->s_h * 128;
			cub->s_y = ((d * cub->tex_s->h) / cub->s_h) / 256;
			col = cub->tex_s->addr[cub->tex_s->w * cub->s_y + cub->s_x];
			if (col != 0)
				ft_pixel_put(cub->img, j, y, col);
			y++;
		}
	}
}

int			draw_sprites(t_cub *cub, double *z)
{
	int		i;
	int		j;

	if (!(cub->s_order = (int *)malloc(sizeof(int) * cub->xs)))
		return (cub->error = BASIC_ERROR);
	if (!(cub->s_dist = (double *)malloc(sizeof(double) * cub->xs)))
		return (cub->error = BASIC_ERROR);
	init_sprites(cub);
	i = -1;
	while (++i < cub->xs)
	{
		init_matrix(cub, i);
		j = cub->s_start_x - 1;
		while (j < cub->s_end_x)
		{
			cub->s_x = (int)(256 * (++j - (-cub->s_w / 2 + cub->spr_scr_x))
					* cub->tex_s->w / cub->s_w / 256);
			dis_px(cub, j, z, i);
		}
	}
	if (cub->s_order)
		free(cub->s_order);
	if (cub->s_dist)
		free(cub->s_dist);
	return (SUCCESS);
}
