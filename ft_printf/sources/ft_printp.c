/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 18:14:02 by ivloisy           #+#    #+#             */
/*   Updated: 2020/04/09 18:14:05 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*ft_define_s(unsigned long long p, t_conv conv)
{
	char	*s;

	if (p == 0 && conv.prec == 0 && conv.dot == 1)
		s = ft_strdup("");
	else
		s = ft_ulltoa_base(p, 16);
	return (s);
}

static int	ft_printprec(t_conv conv, int l)
{
	int		j;

	j = 0;
	while (j < conv.prec - l && conv.prec > l)
		j += ft_putchar_r('0');
	return (j);
}

static int	ft_printflag(t_conv conv, int l)
{
	int		j;
	int		x;

	j = 0;
	x = 0;
	if (conv.prec > l - 2)
		x = conv.prec - (l - 2);
	l = l + x;
	while (j < conv.width - l)
	{
		if (conv.zero == 1 && conv.dot == 0 && conv.minus == 0)
			j += ft_putchar_r('0');
		else
			j += ft_putchar_r(' ');
	}
	return (j);
}

static int	ft_printconv(t_conv conv, char *s, int l)
{
	int		i;

	i = 0;
	if (conv.zero == 0 && conv.minus == 0)
		i += ft_printflag(conv, l);
	if (conv.zero == 0)
		i += ft_putstr_r("0x");
	if (conv.zero == 1 && conv.dot == 0)
		i += ft_putstr_r("0x");
	if (conv.zero == 1 && conv.minus == 0)
		i += ft_printflag(conv, l);
	if (conv.zero == 1 && conv.dot == 1)
		i += ft_putstr_r("0x");
	i += ft_printprec(conv, ft_strlen(s));
	i += ft_putstr_r(s);
	if (conv.minus == 1)
		i += ft_printflag(conv, l);
	return (i);
}

int			ft_printp(long long p, t_conv conv)
{
	unsigned long long	ullp;
	char				*s;
	int					i;
	int					l;

	ullp = (unsigned long long)p;
	if (ullp < 0)
		ullp *= -1;
	s = ft_define_s(ullp, conv);
	i = 0;
	l = (int)ft_strlen(s) + 2;
	i += ft_printconv(conv, s, l);
	free(s);
	s = NULL;
	return (i);
}
