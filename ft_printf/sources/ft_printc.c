/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 18:13:17 by ivloisy           #+#    #+#             */
/*   Updated: 2020/04/09 18:13:19 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_printflag(t_conv conv)
{
	int		j;

	j = 0;
	while (j < conv.width - 1)
	{
		if (conv.zero == 1 && conv.minus == 0)
			j += ft_putchar_r('0');
		else
			j += ft_putchar_r(' ');
	}
	return (j);
}

int			ft_printc(char c, t_conv conv)
{
	int		i;

	i = 0;
	if (conv.minus == 1)
		i += ft_putchar_r(c);
	i += ft_printflag(conv);
	if (conv.minus == 0)
		i += ft_putchar_r(c);
	return (i);
}
