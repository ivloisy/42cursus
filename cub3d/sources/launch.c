/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:16:08 by ivloisy           #+#    #+#             */
/*   Updated: 2021/02/03 13:16:09 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cubed.h"

static int	keypress(int keycode, t_cub *cub)
{
	if (keycode == 65307)
		exit_error(cub);
	if (keycode == 119)
		cub->forward = 1;
	if (keycode == 115)
		cub->back = 1;
	if (keycode == 97)
		cub->left = 1;
	if (keycode == 100)
		cub->right = 1;
	if (keycode == 65361)
		cub->rotatel = 1;
	if (keycode == 65363)
		cub->rotater = 1;
	return (SUCCESS);
}

static int	keyrelease(int keycode, t_cub *cub)
{
	if (keycode == 119)
		cub->forward = 0;
	if (keycode == 115)
		cub->back = 0;
	if (keycode == 97)
		cub->left = 0;
	if (keycode == 100)
		cub->right = 0;
	if (keycode == 65361)
		cub->rotatel = 0;
	if (keycode == 65363)
		cub->rotater = 0;
	return (SUCCESS);
}

int			get_tex(t_cub *cub)
{
	if ((cub->tex_sb = new_texture(cub, "./textures/grass.xpm")) == NULL)
		return (cub->error = TEX_ERROR);
	if ((cub->tex_no = new_texture(cub, cub->no_p)) == NULL)
		return (cub->error = TEX_ERROR);
	if ((cub->tex_so = new_texture(cub, cub->so_p)) == NULL)
		return (cub->error = TEX_ERROR);
	if ((cub->tex_we = new_texture(cub, cub->we_p)) == NULL)
		return (cub->error = TEX_ERROR);
	if ((cub->tex_ea = new_texture(cub, cub->ea_p)) == NULL)
		return (cub->error = TEX_ERROR);
	if ((cub->tex_s = new_texture(cub, cub->s_p)) == NULL)
		return (cub->error = TEX_ERROR);
	return (SUCCESS);
}

static int	run_window(t_cub *cub)
{
	if (display(cub) != SUCCESS)
		return (cub->error);
	mlx_put_image_to_window(cub->ptr, cub->win, cub->img->ptr, 0, 0);
	return (SUCCESS);
}

int			launch(t_cub *cub)
{
	int		x;
	int		y;

	if ((cub->ptr = mlx_init()) == NULL)
		return (MLX_ERROR);
	if ((cub->error = get_tex(cub)) != SUCCESS)
		return (cub->error);
	mlx_get_screen_size(cub->ptr, &x, &y);
	if (cub->w > x)
		cub->w = x;
	if (cub->h > y)
		cub->h = y;
	if ((cub->win = mlx_new_window(cub->ptr, cub->w, cub->h, "Cub3D")) == NULL)
		return (MLX_ERROR);
	mlx_hook(cub->win, 33, 1L << 0, ft_close, cub);
	mlx_hook(cub->win, 2, 1L << 0, keypress, cub);
	mlx_hook(cub->win, 3, 1L << 1, keyrelease, cub);
	mlx_loop_hook(cub->ptr, run_window, cub);
	mlx_loop(cub->ptr);
	return (SUCCESS);
}
