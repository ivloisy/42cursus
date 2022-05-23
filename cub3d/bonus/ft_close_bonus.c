/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:08:41 by ivloisy           #+#    #+#             */
/*   Updated: 2021/02/03 13:08:42 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed_bonus.h"

int		ft_close(int keycode, t_cub cub)
{
	cub.error = NO_ERROR;
	if (keycode == 65307)
		exit(EXIT_SUCCESS);
	exit_error(&cub);
	return (0);
}
