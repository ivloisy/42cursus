/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_shade_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:07:07 by ivloisy           #+#    #+#             */
/*   Updated: 2021/02/03 13:07:10 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cubed_bonus.h"

int		add_shade(double dist, int color)
{
	double	r;
	double	g;
	double	b;

	if (dist <= 0.0)
		return (color);
	if (dist >= 1.0)
		return (0x000000);
	r = get_r(color) * (1 - dist);
	g = get_g(color) * (1 - dist);
	b = get_b(color) * (1 - dist);
	return ((int)b << 16 | (int)g << 8 | (int)r);
}
