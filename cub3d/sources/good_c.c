/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   good_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 13:15:00 by ivloisy           #+#    #+#             */
/*   Updated: 2021/02/03 13:15:01 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cubed.h"

int		path_good_c(int c)
{
	if (c == '.' || c == '/' || c == '-' || c == '_' || ft_isalnum(c)
			|| c == '~')
		return (1);
	else
		return (0);
}

int		color_good_c(int c)
{
	if (ft_isdigit(c) || c == ',' || c == '+')
		return (1);
	else
		return (0);
}

int		map_good_c(int c)
{
	if (ft_strchr(" 012NSEW", c))
		return (1);
	else
		return (0);
}
