/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_tex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:15:57 by ivloisy           #+#    #+#             */
/*   Updated: 2021/02/03 13:15:58 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cubed.h"

int		is_no(char *line, t_cub *cub)
{
	int		i;
	int		j;
	char	*tmp;

	i = 3;
	j = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (!path_good_c(line[i]))
		return (NOT_VALID_NO_ERROR);
	while (path_good_c(line[i + j]))
		j++;
	if (line[i + j] != '\0')
		return (NOT_VALID_NO_ERROR);
	if (!(tmp = ft_strdup(line)))
		return (BASIC_ERROR);
	cub->no_p = tmp;
	if (!(cub->no_p = ft_substr(cub->no_p, i, j)))
		return (BASIC_ERROR);
	free(tmp);
	tmp = NULL;
	cub->no = 1;
	return (SUCCESS);
}

int		is_so(char *line, t_cub *cub)
{
	int		i;
	int		j;
	char	*tmp;

	i = 3;
	j = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (!path_good_c(line[i]))
		return (NOT_VALID_SO_ERROR);
	while (path_good_c(line[i + j]))
		j++;
	if (line[i + j] != '\0')
		return (NOT_VALID_SO_ERROR);
	if (!(tmp = ft_strdup(line)))
		return (BASIC_ERROR);
	cub->so_p = tmp;
	if (!(cub->so_p = ft_substr(cub->so_p, i, j)))
		return (BASIC_ERROR);
	free(tmp);
	tmp = NULL;
	cub->so = 1;
	return (SUCCESS);
}

int		is_we(char *line, t_cub *cub)
{
	int		i;
	int		j;
	char	*tmp;

	i = 3;
	j = 0;
	while (line[i] == ' ')
		i++;
	if (!path_good_c(line[i]))
		return (NOT_VALID_WE_ERROR);
	while (path_good_c(line[i + j]))
		j++;
	if (line[i + j] != '\0')
		return (NOT_VALID_WE_ERROR);
	if (!(tmp = ft_strdup(line)))
		return (BASIC_ERROR);
	cub->we_p = tmp;
	if (!(cub->we_p = ft_substr(cub->we_p, i, j)))
		return (BASIC_ERROR);
	free(tmp);
	tmp = NULL;
	cub->we = 1;
	return (SUCCESS);
}

int		is_ea(char *line, t_cub *cub)
{
	int		i;
	int		j;
	char	*tmp;

	i = 3;
	j = 0;
	while (line[i] == ' ')
		i++;
	if (!path_good_c(line[i]))
		return (NOT_VALID_EA_ERROR);
	while (path_good_c(line[i + j]))
		j++;
	if (line[i + j] != '\0')
		return (NOT_VALID_EA_ERROR);
	if (!(tmp = ft_strdup(line)))
		return (BASIC_ERROR);
	cub->ea_p = tmp;
	if (!(cub->ea_p = ft_substr(cub->ea_p, i, j)))
		return (BASIC_ERROR);
	free(tmp);
	tmp = NULL;
	cub->ea = 1;
	return (SUCCESS);
}

int		is_s(char *line, t_cub *cub)
{
	int		i;
	int		j;
	char	*tmp;

	i = 2;
	j = 0;
	while (line[i] == ' ')
		i++;
	if (!path_good_c(line[i]))
		return (NOT_VALID_S_ERROR);
	while (path_good_c(line[i + j]))
		j++;
	if (line[i + j] != '\0')
		return (NOT_VALID_S_ERROR);
	if (!(tmp = ft_strdup(line)))
		return (BASIC_ERROR);
	cub->s_p = tmp;
	if (!(cub->s_p = ft_substr(cub->s_p, i, j)))
		return (BASIC_ERROR);
	free(tmp);
	tmp = NULL;
	cub->s = 1;
	return (SUCCESS);
}
