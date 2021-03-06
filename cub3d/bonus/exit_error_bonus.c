/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:08:29 by ivloisy           #+#    #+#             */
/*   Updated: 2021/02/03 13:08:31 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed_bonus.h"

static void	put_error(int x)
{
	if (x == 3)
		ft_putstr_fd("The number of arguments is not valid.", 1);
	else if (x == 4)
		ft_putstr_fd("It is not a .cub file.", 1);
	else if (x == 5)
		ft_putstr_fd("Only the --save flag is valid.", 1);
	else if (x == 6)
		ft_putstr_fd("It is not a valid file.", 1);
	else if (x == 7)
		ft_putstr_fd("It is not a valid resolution.", 1);
	else if (x == 8)
		ft_putstr_fd("It is not a valid North texture.", 1);
	else if (x == 9)
		ft_putstr_fd("It is not a valid South texture.", 1);
	else if (x == 10)
		ft_putstr_fd("It is not a valid West texture.", 1);
	else if (x == 11)
		ft_putstr_fd("It is not a valid East texture.", 1);
	else if (x == 12)
		ft_putstr_fd("It is not a valid Sprite texture.", 1);
	else if (x == 13)
		ft_putstr_fd("It is not a valid Floor line.", 1);
	else if (x == 14)
		ft_putstr_fd("It is not a valid Floor color.", 1);
}

static void	put_error2(int x)
{
	if (x == 15)
		ft_putstr_fd("It is not a valid Floor texture.", 1);
	else if (x == 16)
		ft_putstr_fd("It is not a valid Ceil line.", 1);
	else if (x == 17)
		ft_putstr_fd("It is not a valid Ceil color.", 1);
	else if (x == 18)
		ft_putstr_fd("It is not a valid Ceil texture.", 1);
	else if (x == 19)
		ft_putstr_fd("It is not a valid map.", 1);
	else if (x == 20)
		ft_putstr_fd("The number of players is not valid.", 1);
	else if (x == 21)
		ft_putstr_fd("MLX.", 1);
	else if (x == 22)
		ft_putstr_fd("Image not loaded.", 1);
	else if (x == 23)
		ft_putstr_fd("Textures not loaded.", 1);
	else if (x == 24)
		ft_putstr_fd("Floor texture not loaded.", 1);
	else if (x == 25)
		ft_putstr_fd("Ceil textures not loaded.", 1);
	else if (x == 26)
		ft_putstr_fd("Read function return -1.", 1);
}

void		exit_error(t_cub *cub)
{
	if (cub->error != NO_ERROR && cub->error != BASIC_ERROR)
	{
		if (cub->error != 1)
		{
			ft_putstr_fd("Error\n", 1);
			ft_putnbr_fd(cub->error, 1);
			ft_putstr_fd(" : ", 1);
		}
		if (cub->error > 2 && cub->error < 15)
			put_error(cub->error);
		if (cub->error > 14)
			put_error2(cub->error);
		if (cub->error != 1)
			ft_putchar_fd('\n', 1);
	}
	if (cub->error == BASIC_ERROR)
		perror("Error\nerrno ");
	exit(EXIT_FAILURE);
}
