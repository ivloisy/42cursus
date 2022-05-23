/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:12:13 by ivloisy           #+#    #+#             */
/*   Updated: 2021/02/03 13:12:14 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cubed_bonus.h"

static int	bitmap(t_cub *cub, int fd)
{
	int		i;

	i = cub->img->w * cub->img->h - 1;
	while (i >= 0)
	{
		write(fd, &cub->img->addr[i * cub->img->bpp / 8], 4);
		i--;
	}
	return (SUCCESS);
}

static void	mir_verti_pixel(t_cub *cub, int line, int *e, int f)
{
	char	c;
	int		k;

	k = 3;
	while (k >= 0)
	{
		c = cub->img->addr[*e + (line * cub->img->line_length)];
		cub->img->addr[*e + (line * cub->img->line_length)] =
				cub->img->addr[f - k + (line * cub->img->line_length - 1)];
		cub->img->addr[f - k + (line * cub->img->line_length - 1)] = c;
		k--;
		*e = *e + 1;
	}
}

static int	mir_verti(t_cub *cub)
{
	int		line;
	int		e;
	int		f;

	line = 0;
	while (line < cub->h)
	{
		e = 0;
		f = cub->img->line_length;
		while (e < f && e != f)
		{
			mir_verti_pixel(cub, line, &e, f);
			f -= 4;
		}
		line++;
	}
	return (SUCCESS);
}

static int	info_header(t_cub *cub, int fd)
{
	int		info_size;
	int		plane;
	int		i;

	info_size = 40;
	plane = 1;
	write(fd, &info_size, 4);
	write(fd, &cub->img->w, 4);
	write(fd, &cub->img->h, 4);
	write(fd, &plane, 2);
	write(fd, &cub->img->bpp, 2);
	i = 0;
	while (i < 28)
	{
		write(fd, "\0", 1);
		i++;
	}
	return (SUCCESS);
}

int			save(t_cub *cub)
{
	t_save	save;

	if ((cub->ptr = mlx_init()) == NULL)
		return (MLX_ERROR);
	if ((cub->error = get_tex(cub)) != SUCCESS)
		return (cub->error);
	if ((cub->error = display(cub)) != SUCCESS)
		return (cub->error);
	save.fd = open("cub3d_bonus.bmp", O_CREAT | O_WRONLY, S_IRWXU);
	save.size = 14 + 40 + 4 + (cub->img->w * cub->img->h) * 4;
	save.pix = 14 + 40 + 4;
	write(save.fd, "BM", 2);
	write(save.fd, &save.size, 4);
	write(save.fd, "\0\0\0\0", 4);
	write(save.fd, &save.pix, 4);
	info_header(cub, save.fd);
	mir_verti(cub);
	bitmap(cub, save.fd);
	close(save.fd);
	return (SUCCESS);
}
