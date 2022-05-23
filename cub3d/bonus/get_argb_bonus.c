/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argb_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:09:14 by ivloisy           #+#    #+#             */
/*   Updated: 2021/02/03 13:09:15 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cubed_bonus.h"

int		get_rgb(t_rgb *rgb)
{
	return (rgb->r << 16 | rgb->g << 8 | rgb->b);
}

int		get_a(int argb)
{
	return (argb & 0xFF);
}

int		get_r(int rgb)
{
	return (rgb & 0xFF);
}

int		get_g(int rgb)
{
	return ((rgb >> 8) & 0xFF);
}

int		get_b(int rgb)
{
	return ((rgb >> 16) & 0xFF);
}
