/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:15:47 by ivloisy           #+#    #+#             */
/*   Updated: 2021/02/03 13:15:48 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

static int	get_x(char *line, t_cub *cub, int i)
{
	int		j;

	j = 0;
	while (ft_isdigit(line[j + i]))
	{
		cub->w = (cub->w * 10) + (line[j + i] - '0');
		j++;
	}
	return (j);
}

static int	get_y(char *line, t_cub *cub, int i)
{
	int		j;

	j = 0;
	while (ft_isdigit(line[j + i]))
	{
		cub->h = (cub->h * 10) + (line[j + i] - '0');
		j++;
	}
	return (j);
}

int			is_r(char *line, t_cub *cub)
{
	int		i;

	i = 2;
	cub->w = 0;
	cub->h = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == '+')
		i++;
	if (!ft_isdigit(line[i]))
		return (NOT_VALID_R_ERROR);
	i += get_x(line, cub, i);
	while (line[i] == ' ')
		i++;
	if (line[i] == '+')
		i++;
	if (!ft_isdigit(line[i]))
		return (NOT_VALID_R_ERROR);
	i += get_y(line, cub, i);
	if (line[i] != '\0')
		return (NOT_VALID_R_ERROR);
	cub->r = 1;
	return (SUCCESS);
}
