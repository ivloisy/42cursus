/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 18:13:48 by ivloisy           #+#    #+#             */
/*   Updated: 2020/04/09 18:13:51 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_printconv(char *s, t_conv conv)
{
	int		j;

	j = 0;
	if (conv.prec < (int)ft_strlen(s) && conv.dot == 1)
		while (j < conv.prec)
			j += ft_putchar_r(s[j]);
	else
		j += ft_putstr_r(s);
	return (j);
}

static int	ft_printflag(t_conv conv, int l)
{
	int		j;
	int		k;

	j = 0;
	if (conv.prec < l && conv.dot == 1)
		k = conv.prec;
	else if (conv.prec < l && conv.dot == 0)
		k = l;
	else
		k = l;
	while (j < conv.width - k)
	{
		if (conv.zero == 1 && conv.minus == 0)
			j += ft_putchar_r('0');
		else
			j += ft_putchar_r(' ');
	}
	return (j);
}

int			ft_prints(char *s, t_conv conv)
{
	int		i;
	int		l;

	if (!s)
		s = "(null)";
	i = 0;
	l = (int)ft_strlen(s);
	if (conv.minus == 0)
		i += ft_printflag(conv, l);
	i += ft_printconv(s, conv);
	if (conv.minus == 1)
		i += ft_printflag(conv, l);
	return (i);
}
