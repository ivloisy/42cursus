/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mir_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:11:34 by ivloisy           #+#    #+#             */
/*   Updated: 2021/02/03 13:11:35 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cubed_bonus.h"

void	mir(t_cub *cub)
{
	int		x;
	int		y;

	y = cub->h / 2 + 1;
	while (y > cub->h / 2 - 2)
	{
		x = cub->w / 2 - 15;
		while (x < cub->w / 2 + 15)
		{
			if (x < cub->w / 2 - 5 || (x > cub->w / 2 - 2 && x < cub->w / 2 + 2)
					|| x > cub->w / 2 + 5)
				ft_pixel_put(cub->img, x, y, 0x4488FF);
			x++;
		}
		y--;
	}
	x = cub->w / 2 + 1;
	while (x > cub->w / 2 - 2)
	{
		y = cub->h / 2 - 14;
		while (++y < cub->h / 2 + 14)
			if (y < cub->h / 2 - 4 || y > cub->h / 2 + 4)
				ft_pixel_put(cub->img, x, y, 0x4488FF);
		x--;
	}
}
