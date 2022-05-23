/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:14:32 by ivloisy           #+#    #+#             */
/*   Updated: 2021/02/03 13:14:33 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cubed.h"

static int	check_zero(t_cub *cub, int i, int j)
{
	if (!cub->map[j - 1][i] || !cub->map[j + 1][i] || !cub->map[j][i - 1]
			|| !cub->map[j][i + 1] || cub->map[j - 1][i] == ' '
			|| cub->map[j + 1][i] == ' ' || cub->map[j][i - 1] == ' '
			|| cub->map[j][i + 1] == ' ')
		return (0);
	return (1);
}

static int	check_tap(t_cub *cub)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (cub->map[j])
	{
		while (cub->map[j][i])
		{
			if (ft_strchr("02NSEW", cub->map[j][i]))
			{
				if (!(check_zero(cub, i, j)))
					return (NOT_VALID_M_ERROR);
				if (ft_strchr("NSEW", cub->map[j][i]))
					cub->player++;
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (SUCCESS);
}

static int	get_tab(t_cub *cub, int x)
{
	int		i;
	int		j;
	char	*tmp1;
	char	*tmp2;

	i = 0;
	while (i < x)
	{
		j = 0;
		while (tmp1[j] != '\n')
			j++;
		if (!(cub->map[i] = ft_substr(tmp1, 0, j))
				|| !(tmp2 = ft_substr(tmp1, j + 1, ft_strlen(tmp1) - (j + 1))))
			return (BASIC_ERROR);
		free(tmp1);
		if (!(tmp1 = ft_strdup(tmp2)))
			return (BASIC_ERROR);
		free(tmp2);
		i++;
	}
	cub->map[i] = NULL;
	free(tmp1);
	return (SUCCESS);
}

int			get_map(t_cub *cub)
{
	cub->player = 0;
	if (!(cub->map = (char **)malloc(sizeof(char *) * cub->m)))
		return (BASIC_ERROR);
	cub->map[0] = NULL;
	if ((cub->error = get_tab(cub, cub->m)) != SUCCESS)
		return (cub->error);
	if ((cub->error = check_tap(cub)) != SUCCESS)
		return (cub->error);
	if (cub->player > 1 || cub->player == 0)
		return (cub->error = NB_PLAY_ERROR);
	return (SUCCESS);
}
