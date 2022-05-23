/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:13:05 by ivloisy           #+#    #+#             */
/*   Updated: 2021/02/03 13:13:06 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cubed.h"

static void	get_dir(t_cub *cub)
{
	if (cub->pos_dir == 'N')
	{
		cub->plr.dir.y = -1.0;
		cub->plr.plan.x = 0.66;
	}
	if (cub->pos_dir == 'S')
	{
		cub->plr.plan.x = -0.66;
		cub->plr.dir.y = 1.0;
	}
	if (cub->pos_dir == 'W')
	{
		cub->plr.dir.x = -1.0;
		cub->plr.plan.y = -0.66;
	}
	if (cub->pos_dir == 'E')
	{
		cub->plr.dir.x = 1.0;
		cub->plr.plan.y = 0.66;
	}
}

static void	get_pos(t_cub *cub, int i, int j)
{
	int		x;
	int		y;

	x = 0;
	y = -1;
	if (cub->map[j][i] == 'N')
		cub->pos_dir = 'N';
	else if (cub->map[j][i] == 'S')
		cub->pos_dir = 'S';
	else if (cub->map[j][i] == 'W')
		cub->pos_dir = 'W';
	else if (cub->map[j][i] == 'E')
		cub->pos_dir = 'E';
	get_dir(cub);
	cub->plr.x = (double)i + 0.5;
	cub->plr.y = (double)j + 0.5;
	while (cub->map[++y])
		if (x < (int)ft_strlen(cub->map[y]))
			x = (int)ft_strlen(cub->map[y]);
	cub->m_x = x;
	cub->m_y = y;
	cub->player++;
}

static int	check_zero(t_cub *cub, int i, int j)
{
	if (i == 0 || j == 0 || j == cub->m - 1)
		return (0);
	if (!cub->map[j - 1][i] || !cub->map[j + 1][i]
			|| !cub->map[j][i - 1] || !cub->map[j][i + 1]
			|| cub->map[j - 1][i] == ' ' || cub->map[j + 1][i] == ' '
			|| cub->map[j][i - 1] == ' ' || cub->map[j][i + 1] == ' ')
		return (0);
	return (1);
}

static int	get_sprites(t_cub *cub, int j, int i)
{
	int		x;
	t_vec	*tmp;

	x = 0;
	if (!(tmp = (t_vec *)malloc(sizeof(t_vec) * (cub->xs + 2))))
		return (BASIC_ERROR);
	while (x < cub->xs)
	{
		tmp[x] = cub->sprite[x];
		x++;
	}
	tmp[x].y = j + 0.5;
	tmp[x].x = i + 0.5;
	free(cub->sprite);
	cub->sprite = tmp;
	x = 0;
	cub->xs++;
	return (SUCCESS);
}

int			check_map(t_cub *cub)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (cub->map[++j])
	{
		while (cub->map[j][++i])
		{
			if (ft_strchr("02NSEW", cub->map[j][i]))
			{
				if (!(check_zero(cub, i, j)))
					return (NOT_VALID_M_ERROR);
				if (ft_strchr("NSEW", cub->map[j][i]))
					get_pos(cub, i, j);
				if (cub->map[j][i] == '2')
					if (get_sprites(cub, j, i) != SUCCESS)
						return (BASIC_ERROR);
			}
		}
		i = -1;
	}
	return (SUCCESS);
}
