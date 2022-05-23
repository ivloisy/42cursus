/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isflag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 18:12:15 by ivloisy           #+#    #+#             */
/*   Updated: 2020/04/09 18:12:18 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_conv	ft_isnum(const char *f, t_conv conv, int i)
{
	if (f[i] == '0' && !ft_isdigit(f[i - 1]))
		conv.zero = 1;
	if (conv.star == 1)
		conv.width = 0;
	conv.width = (conv.width * 10) + (f[i] - '0');
	return (conv);
}

int		ft_isdot(const char *f, t_conv *conv, int i)
{
	conv->dot = 1;
	if (conv->prec > 0)
		conv->prec = 0;
	while (ft_isdigit(f[i + 1]))
	{
		i++;
		conv->prec = (conv->prec * 10) + (f[i] - '0');
	}
	return (i);
}

t_conv	ft_isminus(t_conv conv)
{
	conv.minus = 1;
	return (conv);
}

t_conv	ft_isstar(const char *f, t_conv conv, va_list arg, int i)
{
	conv.star = 1;
	if (f[i - 1] == '.')
	{
		conv.prec = va_arg(arg, int);
		if (conv.prec < 0)
		{
			conv.dot = 0;
			conv.prec = 0;
		}
	}
	else
	{
		conv.width = va_arg(arg, int);
		if (conv.width < 0)
		{
			conv.minus = 1;
			conv.width *= -1;
		}
	}
	return (conv);
}
