/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:11:51 by ivloisy           #+#    #+#             */
/*   Updated: 2021/02/03 13:11:52 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cubed_bonus.h"

static void	move_f_b(t_cub *cub, double speed)
{
	if (cub->forward == 1)
		move_f(cub, speed);
	if (cub->back == 1)
		move_b(cub, speed);
}

static void	move_l_r(t_cub *cub, double speed)
{
	if (cub->left == 1)
		move_l(cub, speed);
	if (cub->right == 1)
		move_r(cub, speed);
}

static void	rotate(t_cub *cub, double speed, double screw)
{
	double	dir;
	double	plan;

	dir = cub->plr.dir.x;
	plan = cub->plr.plan.x;
	cub->plr.dir.x = cub->plr.dir.x * cos(screw * speed)
			- cub->plr.dir.y * sin(screw * speed);
	cub->plr.dir.y = dir * sin(screw * speed)
		+ cub->plr.dir.y * cos(screw * speed);
	cub->plr.plan.x = cub->plr.plan.x * cos(screw * speed)
		- cub->plr.plan.y * sin(screw * speed);
	cub->plr.plan.y = plan * sin(screw * speed)
		+ cub->plr.plan.y * cos(screw * speed);
}

void		move(t_cub *cub)
{
	if (cub->forward == 1 || cub->back == 1)
		move_f_b(cub, 0.1);
	if (cub->left == 1 || cub->right == 1)
		move_l_r(cub, 0.1);
	if (cub->rotatel == 1)
		rotate(cub, 0.1, -1);
	if (cub->rotater == 1)
		rotate(cub, 0.1, 1);
}
