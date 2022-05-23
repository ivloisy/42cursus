/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:13:14 by ivloisy           #+#    #+#             */
/*   Updated: 2021/02/03 13:13:15 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

static int	arg_check(int ac, char **av, t_cub *cub)
{
	if (ac < 2 || ac > 3)
		return (NB_ARG_ERROR);
	else
	{
		if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub", 4) != 0)
			return (FILE_TYPE_ERROR);
		if (ac == 3 && ft_strncmp(av[2], "--save", ft_strlen(av[2])) != 0)
			return (FLAG_ERROR);
		if (ac == 3 && ft_strlen(av[2]) != 6)
			return (FLAG_ERROR);
		if (ac == 3)
			cub->save = 1;
	}
	return (SUCCESS);
}

static int	is_line(char *line, t_cub *cub)
{
	if (!ft_strncmp(line, "R ", 2) && cub->r == 0 && cub->m == 0)
		return (cub->error = is_r(line, cub));
	if (!ft_strncmp(line, "NO ", 3) && cub->no == 0 && cub->m == 0)
		return (cub->error = is_no(line, cub));
	if (!ft_strncmp(line, "SO ", 3) && cub->so == 0 && cub->m == 0)
		return (cub->error = is_so(line, cub));
	if (!ft_strncmp(line, "WE ", 3) && cub->we == 0 && cub->m == 0)
		return (cub->error = is_we(line, cub));
	if (!ft_strncmp(line, "EA ", 3) && cub->ea == 0 && cub->m == 0)
		return (cub->error = is_ea(line, cub));
	if (!ft_strncmp(line, "S ", 2) && cub->s == 0 && cub->m == 0)
		return (cub->error = is_s(line, cub));
	if (!ft_strncmp(line, "F ", 2) && cub->f == 0 && cub->m == 0)
		return (cub->error = is_f(line, cub));
	if (!ft_strncmp(line, "C ", 2) && cub->c == 0 && cub->m == 0)
		return (cub->error = is_c(line, cub));
	if (line[0] == '\0' && cub->m == 0 && (cub->r == 1 || cub->no == 1
			|| cub->so == 1 || cub->we == 1 || cub->ea == 1 || cub->s == 1
			|| cub->f == 1 || cub->c == 1))
		return (SUCCESS);
	if ((line[0] == ' ' || line[0] == '1') && cub->r == 1 && cub->no == 1
			&& cub->so == 1 && cub->we == 1 && cub->ea == 1 && cub->s == 1
			&& cub->f == 1 && cub->c == 1)
		return (cub->error = is_m(line, cub));
	return (NOT_VALID_FILE_ERROR);
}

static int	get_info(int fd, t_cub *cub)
{
	int		ret;
	char	*line;

	ret = 0;
	if (!(cub->map = (char **)malloc(sizeof(char *))))
		return (BASIC_ERROR);
	cub->map[0] = NULL;
	while ((ret = get_next_line(fd, &line)) > 0
			&& (cub->error = is_line(line, cub)) == SUCCESS)
		free(line);
	free(line);
	line = NULL;
	if (ret == -1)
		return (READ_ERROR);
	if (cub->error != SUCCESS)
		return (cub->error);
	if (cub->r == 0 || cub->no == 0 || cub->so == 0 || cub->we == 0
			|| cub->ea == 0 || cub->s == 0 || cub->f == 0 || cub->c == 0
			|| cub->m == 0)
		return (NOT_VALID_FILE_ERROR);
	if ((cub->error = check_map(cub)) != SUCCESS)
		return (cub->error);
	if (cub->player > 1 || cub->player == 0)
		return (cub->error = NB_PLAY_ERROR);
	return (SUCCESS);
}

int			main(int ac, char **av)
{
	t_cub	cub;
	int		fd;

	ft_bzero(&cub, sizeof(cub));
	if ((cub.error = arg_check(ac, av, &cub)) != SUCCESS)
		exit_error(&cub);
	if ((fd = open(av[1], O_RDONLY)) == -1)
	{
		cub.error = BASIC_ERROR;
		exit_error(&cub);
	}
	if ((cub.error = get_info(fd, &cub)) != SUCCESS)
		exit_error(&cub);
	close(fd);
	if (cub.save == 1)
	{
		if ((cub.error = save(&cub)) != SUCCESS)
			exit_error(&cub);
		exit_error(&cub);
	}
	if (cub.save == 0)
		if ((cub.error = launch(&cub)) != SUCCESS)
			exit_error(&cub);
	return (EXIT_SUCCESS);
}
