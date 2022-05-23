/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_f_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:10:34 by ivloisy           #+#    #+#             */
/*   Updated: 2021/02/03 13:10:35 by ivloisy          ###   ########.fr       */
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

static int	is_f_color(char *line, t_cub *cub, int i)
{
	if (line[i] == '+')
		i++;
	i += get_x(line, i, &(cub->f_c.r));
	if (line[i] != ',')
		return (NOT_VALID_F_C_ERROR);
	else
		i++;
	if (line[i] == '+')
		i++;
	i += get_x(line, i, &(cub->f_c.g));
	if (line[i] != ',')
		return (NOT_VALID_F_C_ERROR);
	else
		i++;
	if (line[i] == '+')
		i++;
	i += get_x(line, i, &(cub->f_c.b));
	if (line[i] != '\0' || cub->f_c.r < 0 || cub->f_c.r > 255
			|| cub->f_c.g < 0 || cub->f_c.g > 255
			|| cub->f_c.b < 0 || cub->f_c.b > 255)
		return (NOT_VALID_F_C_ERROR);
	cub->f = 1;
	return (SUCCESS);
}

static int	is_f_path(char *line, t_cub *cub)
{
	int		i;
	int		j;
	char	*tmp;

	i = 2;
	j = 0;
	while (line[i] == ' ')
		i++;
	if (!path_good_c(line[i]))
		return (NOT_VALID_F_P_ERROR);
	while (path_good_c(line[i + j]))
		j++;
	if (line[i + j] != '\0')
		return (NOT_VALID_F_P_ERROR);
	if (!(tmp = ft_strdup(line)))
		return (BASIC_ERROR);
	cub->f_p = tmp;
	free(tmp);
	tmp = NULL;
	if (!(cub->f_p = ft_substr(cub->f_p, i, j)))
		return (BASIC_ERROR);
	cub->f = 1;
	ft_putstr_fd(cub->f_p, 1);
	return (SUCCESS);
}

static int	get_f(char *line, t_cub *cub, int i)
{
	int		j;
	int		spc;

	j = i;
	spc = i;
	while (color_good_c(line[i]))
		i++;
	if (line[i] != '\0')
		cub->f_color = 0;
	else
		cub->f_color = 1;
	while (path_good_c(line[j]))
		j++;
	if (line[j] != '\0')
		cub->f_path = 0;
	else
		cub->f_path = 1;
	if (cub->f_color == 1 && cub->f_path == 0)
		return (is_f_color(line, cub, spc));
	else if (cub->f_path == 1 && cub->f_color == 0)
		return (is_f_path(line, cub));
	return (NOT_VALID_F_ERROR);
}

int			is_f(char *line, t_cub *cub)
{
	int		i;

	i = 2;
	cub->f_color = 0;
	cub->f_path = 0;
	cub->f_c.r = 0;
	cub->f_c.g = 0;
	cub->f_c.b = 0;
	while (line[i] == ' ')
		i++;
	if (ft_isdigit(line[i]) || path_good_c(line[i]))
		return (get_f(line, cub, i));
	else
		return (NOT_VALID_F_ERROR);
	return (SUCCESS);
}
