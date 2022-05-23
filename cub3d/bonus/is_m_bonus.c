/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_m_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:10:43 by ivloisy           #+#    #+#             */
/*   Updated: 2021/02/03 13:10:44 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cubed_bonus.h"

int		is_m(char *line, t_cub *cub)
{
	int		i;
	char	**tmp;

	i = 0;
	while (line[i] && map_good_c(line[i]))
		i++;
	if (line[i] != '\0')
		return (NOT_VALID_M_ERROR);
	i = -1;
	if (!(tmp = (char **)malloc(sizeof(char *) * (cub->m + 2))))
		return (BASIC_ERROR);
	while (cub->map[++i])
		tmp[i] = cub->map[i];
	tmp[i] = ft_strdup(line);
	tmp[i + 1] = NULL;
	free(cub->map);
	cub->map = tmp;
	i = -1;
	while (tmp[++i])
		cub->map[i] = tmp[i];
	cub->map[i] = NULL;
	cub->m++;
	return (SUCCESS);
}
