/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:15:09 by ivloisy           #+#    #+#             */
/*   Updated: 2021/02/03 13:15:11 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cubed.h"

void	free_img(t_cub *cub, t_img *img)
{
	if (img)
	{
		mlx_destroy_image(cub->ptr, img->ptr);
		free(img);
		img = NULL;
	}
}

t_img	*new_image(t_cub *cub, int w, int h)
{
	t_img	*img;

	if (!(img = malloc(sizeof(t_img))))
		return (NULL);
	if (!(img->ptr = mlx_new_image(cub->ptr, w, h)))
		return (NULL);
	if (!(img->addr = mlx_get_data_addr(img->ptr, &img->bpp,
			&img->line_length, &img->endian)))
		return (NULL);
	img->w = w;
	img->h = h;
	return (img);
}

t_tex	*new_texture(t_cub *cub, char *path)
{
	t_tex *tex;

	if (!(tex = malloc(sizeof(t_img))))
		return (NULL);
	if (!(tex->ptr = mlx_xpm_file_to_image(cub->ptr, path,
		&tex->w, &tex->h)))
	{
		free(tex);
		return (NULL);
	}
	if (!(tex->addr = (int *)mlx_get_data_addr(tex->ptr, &tex->bpp,
		&tex->line_length, &tex->endian)))
	{
		free(tex->ptr);
		free(tex);
		return (NULL);
	}
	return (tex);
}
