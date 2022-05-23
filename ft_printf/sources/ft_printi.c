/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 18:13:36 by ivloisy           #+#    #+#             */
/*   Updated: 2020/04/09 18:13:38 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*ft_define_s(int n, t_conv conv)
{
	char	*s;

	if (n == 0 && conv.prec == 0 && conv.dot == 1)
		s = ft_strdup("");
	else
		s = ft_itoa(n);
	if (s[0] == '-')
		s = ft_strcpy(s, s + 1);
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

	j = 0;
	while (j < conv.width - l)
	{
		if (conv.zero == 1 && conv.dot == 0 && conv.minus == 0)
			j += ft_putchar_r('0');
		else
			j += ft_putchar_r(' ');
	}
	return (j);
}

static int	ft_printconv(t_conv conv, char *s, int l, int neg)
{
	int		i;

	i = 0;
	if (conv.zero == 0 && conv.minus == 0)
		i += ft_printflag(conv, l);
	if (neg == 1 && conv.zero == 0)
		i += ft_putchar_r('-');
	if (neg == 1 && conv.zero == 1 && conv.dot == 0)
		i += ft_putchar_r('-');
	if (conv.zero == 1 && conv.minus == 0)
		i += ft_printflag(conv, l);
	if (neg == 1 && conv.zero == 1 && conv.dot == 1)
		i += ft_putchar_r('-');
	i += ft_printprec(conv, ft_strlen(s));
	i += ft_putstr_r(s);
	if (conv.minus == 1)
		i += ft_printflag(conv, l);
	return (i);
}

int			ft_printi(int n, t_conv conv)
{
	char	*s;
	int		i;
	int		neg;
	int		l;

	neg = 0;
	if (n < 0)
	{
		neg = 1;
		n *= -1;
	}
	s = ft_define_s(n, conv);
	i = 0;
	l = ft_strlen(s) + neg;
	if (conv.prec > (int)ft_strlen(s))
		l = conv.prec + neg;
	i += ft_printconv(conv, s, l, neg);
	free(s);
	s = NULL;
	return (i);
}
