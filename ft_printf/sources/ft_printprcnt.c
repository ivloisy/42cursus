/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printprcnt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 18:14:12 by ivloisy           #+#    #+#             */
/*   Updated: 2020/04/09 18:14:14 by ivloisy          ###   ########.fr       */
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

int			ft_printprcnt(t_conv conv)
{
	int		i;

	i = 0;
	if (conv.minus == 0)
		i += ft_printflag(conv);
	i += ft_putchar_r('%');
	if (conv.minus == 1)
		i += ft_printflag(conv);
	return (i);
}
