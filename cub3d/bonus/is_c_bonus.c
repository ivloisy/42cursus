/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_c_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:10:23 by ivloisy           #+#    #+#             */
/*   Updated: 2021/02/03 13:10:24 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cubed_bonus.h"

static int	get_x(char *line, int i, int *x)
{
	int		j;

	j = 0;
	while (ft_isdigit(line[i + j]))
	{
		*x = (*x * 10) + (line[i + j] - '0');
		j++;
	}
	return (j);
}

static int	is_c_color(char *line, t_cub *cub, int i)
{
	if (line[i] == '+')
		i++;
	i += get_x(line, i, &(cub->c_c.r));
	if (line[i] != ',')
		return (NOT_VALID_C_C_ERROR);
	else
		i++;
	if (line[i] == '+')
		i++;
	i += get_x(line, i, &(cub->c_c.g));
	if (line[i] != ',')
		return (NOT_VALID_C_C_ERROR);
	else
		i++;
	if (line[i] == '+')
		i++;
	i += get_x(line, i, &(cub->c_c.b));
	if (line[i] != '\0' || cub->c_c.r < 0 || cub->c_c.r > 255
			|| cub->c_c.g < 0 || cub->c_c.g > 255
			|| cub->c_c.b < 0 || cub->c_c.b > 255)
		return (NOT_VALID_C_C_ERROR);
	cub->c = 1;
	return (SUCCESS);
}

static int	is_c_path(char *line, t_cub *cub)
{
	int		i;
	int		j;
	char	*tmp;

	i = 2;
	j = 0;
	while (line[i] == ' ')
		i++;
	if (!path_good_c(line[i]))
		return (NOT_VALID_C_P_ERROR);
	while (path_good_c(line[i + j]))
		j++;
	if (line[i + j] != '\0')
		return (NOT_VALID_C_P_ERROR);
	if (!(tmp = ft_strdup(line)))
		return (BASIC_ERROR);
	cub->c_p = tmp;
	free(tmp);
	tmp = NULL;
	if (!(cub->c_p = ft_substr(cub->c_p, i, j)))
		return (BASIC_ERROR);
	cub->c = 1;
	ft_putstr_fd(cub->c_p, 1);
	return (SUCCESS);
}

static int	get_c(char *line, t_cub *cub, int i)
{
	int		j;
	int		spc;

	j = i;
	spc = i;
	while (color_good_c(line[i]))
		i++;
	if (line[i] != '\0')
		cub->c_color = 0;
	else
		cub->c_color = 1;
	while (path_good_c(line[j]))
		j++;
	if (line[j] != '\0')
		cub->c_path = 0;
	else
		cub->c_path = 1;
	if (cub->c_color == 1 && cub->c_path == 0)
		return (is_c_color(line, cub, spc));
	else if (cub->c_path == 1 && cub->c_color == 0)
		return (is_c_path(line, cub));
	return (NOT_VALID_C_ERROR);
}

int			is_c(char *line, t_cub *cub)
{
	int		i;

	i = 2;
	cub->c_color = 0;
	cub->c_path = 0;
	cub->c_c.r = 0;
	cub->c_c.g = 0;
	cub->c_c.b = 0;
	while (line[i] == ' ')
		i++;
	if (ft_isdigit(line[i]) || path_good_c(line[i]))
		return (get_c(line, cub, i));
	else
		return (NOT_VALID_C_ERROR);
	return (SUCCESS);
}
