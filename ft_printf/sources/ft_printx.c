/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 18:15:08 by ivloisy           #+#    #+#             */
/*   Updated: 2020/04/09 18:15:10 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*ft_define_s(int n, t_conv conv)
{
	char	*s;

	if (n == 0 && conv.prec == 0 && conv.dot == 1)
		s = ft_strdup("");
	else
		s = ft_utoa_base(n, 16);
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

static int	ft_printconv(t_conv conv, char *s, int l)
{
	int		i;

	i = 0;
	if (conv.zero == 0 && conv.minus == 0)
		i += ft_printflag(conv, l);
	if (conv.zero == 1 && conv.minus == 0)
		i += ft_printflag(conv, l);
	i += ft_printprec(conv, ft_strlen(s));
	i += ft_putstr_r(s);
	if (conv.minus == 1)
		i += ft_printflag(conv, l);
	return (i);
}

int			ft_printx(int n, t_conv conv)
{
	char	*s;
	int		i;
	int		j;
	int		l;

	s = ft_define_s(n, conv);
	i = 0;
	j = 0;
	l = ft_strlen(s);
	while (j < l && conv.type == 'X')
	{
		s[j] = ft_toupper(s[j]);
		j++;
	}
	if (conv.prec > (int)ft_strlen(s))
		l = conv.prec;
	i += ft_printconv(conv, s, l);
	free(s);
	s = NULL;
	return (i);
}
