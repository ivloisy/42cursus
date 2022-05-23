/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_fblr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:11:59 by ivloisy           #+#    #+#             */
/*   Updated: 2021/02/03 13:12:00 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cubed_bonus.h"

void	move_f(t_cub *cub, double speed)
{
	if (cub->map[(int)cub->plr.y]
			[(int)(cub->plr.x + cub->plr.dir.x * speed * 1.5)] != '1'
			&& cub->map[(int)cub->plr.y]
			[(int)(cub->plr.x + cub->plr.dir.x * speed * 1.5)] != '2'
			&& cub->map[(int)cub->plr.y]
			[(int)(cub->plr.x + cub->plr.dir.x * speed * 1.5)] != ' '
			&& cub->map[(int)cub->plr.y]
			[(int)(cub->plr.x + cub->plr.dir.x * speed * 1.5)])
		cub->plr.x += cub->plr.dir.x * speed;
	if (cub->map[(int)(cub->plr.y + cub->plr.dir.y * speed * 1.5)]
			[(int)cub->plr.x] != '1'
			&& cub->map[(int)(cub->plr.y + cub->plr.dir.y * speed * 1.5)]
			[(int)cub->plr.x] != '2'
			&& cub->map[(int)(cub->plr.y + cub->plr.dir.y * speed * 1.5)]
			[(int)cub->plr.x] != ' '
			&& cub->map[(int)(cub->plr.y + cub->plr.dir.y * speed * 1.5)]
			[(int)cub->plr.x])
		cub->plr.y += cub->plr.dir.y * speed;
}

void	move_b(t_cub *cub, double speed)
{
	if (cub->map[(int)cub->plr.y]
			[(int)(cub->plr.x - cub->plr.dir.x * speed * 1.5)] != '1'
			&& cub->map[(int)cub->plr.y]
			[(int)(cub->plr.x - cub->plr.dir.x * speed * 1.5)] != '2'
			&& cub->map[(int)cub->plr.y]
			[(int)(cub->plr.x - cub->plr.dir.x * speed * 1.5)] != ' '
			&& cub->map[(int)cub->plr.y]
			[(int)(cub->plr.x - cub->plr.dir.x * speed * 1.5)])
		cub->plr.x -= cub->plr.dir.x * speed;
	if (cub->map[(int)(cub->plr.y - cub->plr.dir.y * speed * 1.5)]
			[(int)cub->plr.x] != '1'
			&& cub->map[(int)(cub->plr.y - cub->plr.dir.y * speed * 1.5)]
			[(int)cub->plr.x] != '2'
			&& cub->map[(int)(cub->plr.y - cub->plr.dir.y * speed * 1.5)]
			[(int)cub->plr.x] != ' '
			&& cub->map[(int)(cub->plr.y - cub->plr.dir.y * speed * 1.5)]
			[(int)cub->plr.x])
		cub->plr.y -= cub->plr.dir.y * speed;
}

void	move_l(t_cub *cub, double speed)
{
	if (cub->map[(int)cub->plr.y]
			[(int)(cub->plr.x + cub->plr.dir.y * speed * 1.5)] != '1'
			&& cub->map[(int)cub->plr.y]
			[(int)(cub->plr.x + cub->plr.dir.y * speed * 1.5)] != '2'
			&& cub->map[(int)cub->plr.y]
			[(int)(cub->plr.x + cub->plr.dir.y * speed * 1.5)] != ' '
			&& cub->map[(int)cub->plr.y]
			[(int)(cub->plr.x + cub->plr.dir.y * speed * 1.5)])
		cub->plr.x += cub->plr.dir.y * speed;
	if (cub->map[(int)(cub->plr.y - cub->plr.dir.x * speed * 1.5)]
			[(int)cub->plr.x] != '1'
			&& cub->map[(int)(cub->plr.y - cub->plr.dir.x * speed * 1.5)]
			[(int)cub->plr.x] != '2'
			&& cub->map[(int)(cub->plr.y - cub->plr.dir.x * speed * 1.5)]
			[(int)cub->plr.x] != ' '
			&& cub->map[(int)(cub->plr.y - cub->plr.dir.x * speed * 1.5)]
			[(int)cub->plr.x])
		cub->plr.y -= cub->plr.dir.x * speed;
}

void	move_r(t_cub *cub, double speed)
{
	if (cub->map[(int)cub->plr.y]
			[(int)(cub->plr.x - cub->plr.dir.y * speed * 1.5)] != '1'
			&& cub->map[(int)cub->plr.y]
			[(int)(cub->plr.x - cub->plr.dir.y * speed * 1.5)] != '2'
			&& cub->map[(int)cub->plr.y]
			[(int)(cub->plr.x - cub->plr.dir.y * speed * 1.5)] != ' '
			&& cub->map[(int)cub->plr.y]
			[(int)(cub->plr.x - cub->plr.dir.y * speed * 1.5)])
		cub->plr.x -= cub->plr.dir.y * speed;
	if (cub->map[(int)(cub->plr.y + cub->plr.dir.x * speed * 1.5)]
			[(int)cub->plr.x] != '1'
			&& cub->map[(int)(cub->plr.y + cub->plr.dir.x * speed * 1.5)]
			[(int)cub->plr.x] != '2'
			&& cub->map[(int)(cub->plr.y + cub->plr.dir.x * speed * 1.5)]
			[(int)cub->plr.x] != ' '
			&& cub->map[(int)(cub->plr.y + cub->plr.dir.x * speed * 1.5)]
			[(int)cub->plr.x])
		cub->plr.y += cub->plr.dir.x * speed;
}
