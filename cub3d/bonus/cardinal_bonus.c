/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cardinal_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:07:26 by ivloisy           #+#    #+#             */
/*   Updated: 2021/02/03 13:07:28 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cubed_bonus.h"

static void	if_side(t_cub *cub)
{
	if (cub->ray.stepy > 0)
	{
		cub->ray.cardinal = 'S';
		cub->ray.tex_w = cub->tex_so->w;
		cub->ray.tex_h = cub->tex_so->h;
	}
	if (cub->ray.stepy < 0)
	{
		cub->ray.cardinal = 'N';
		cub->ray.tex_w = cub->tex_no->w;
		cub->ray.tex_h = cub->tex_no->h;
	}
}

void		get_cardinal(t_cub *cub)
{
	if (cub->ray.side == 0)
	{
		if (cub->ray.stepx > 0)
		{
			cub->ray.cardinal = 'E';
			cub->ray.tex_w = cub->tex_ea->w;
			cub->ray.tex_h = cub->tex_ea->h;
		}
		if (cub->ray.stepx < 0)
		{
			cub->ray.cardinal = 'W';
			cub->ray.tex_w = cub->tex_we->w;
			cub->ray.tex_h = cub->tex_we->h;
		}
	}
	if (cub->ray.side == 1)
		if_side(cub);
}
