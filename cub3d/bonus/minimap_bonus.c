/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:11:25 by ivloisy           #+#    #+#             */
/*   Updated: 2021/02/03 13:11:26 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cubed_bonus.h"

static void	square(t_cub *cub, int x, int y, int color)
{
	int		i;
	int		j;

	i = (x * 10) + 20;
	j = (y * 10) + 20;
	while (j < (y * 10) + 30)
	{
		while (i < (x * 10) + 30)
		{
			ft_pixel_put(cub->img, i, j, color);
			i++;
		}
		i = (x * 10) + 20;
		j++;
	}
}

static void	player(t_cub *cub)
{
	double		i;
	double		j;

	i = (cub->plr.x * 10) + 18.0;
	j = (cub->plr.y * 10) + 18.0;
	while (j < (cub->plr.y * 10) + 22.0)
	{
		while (i < (cub->plr.x * 10) + 22.0)
		{
			ft_pixel_put(cub->img, i, j, 0xFFFFFF);
			i++;
		}
		i = (cub->plr.x * 10) + 18.0;
		j++;
	}
}

void		minimap(t_cub *cub)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < cub->m_y && cub->map[y])
	{
		while (x < cub->m_x && cub->map[y][x])
		{
			if (cub->map[y][x] == '1')
				square(cub, x, y, 0x4488FF);
			if (cub->map[y][x] == '2')
				square(cub, x, y, 0x1155CC);
			if (ft_strchr("0NSEW", cub->map[y][x]))
				square(cub, x, y, 0x4488FF / 2);
			x++;
		}
		x = 0;
		y++;
	}
	player(cub);
}
