/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 18:00:20 by ivloisy           #+#    #+#             */
/*   Updated: 2020/04/09 18:00:26 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_conv	ft_init_conv(t_conv conv)
{
	conv.width = 0;
	conv.prec = 0;
	conv.minus = 0;
	conv.zero = 0;
	conv.dot = 0;
	conv.star = 0;
	conv.type = 0;
	return (conv);
}

static int		ft_parsing(const char *f, t_conv *conv, va_list arg, int i)
{
	while (f[i] && (ft_strchr("cspdiuxX%-.*", f[i]) || ft_isdigit(f[i])))
	{
		if (ft_isdigit(f[i]))
			*conv = ft_isnum(f, *conv, i);
		else if (f[i] == '.')
			i = ft_isdot(f, conv, i);
		else if (f[i] == '-')
			*conv = ft_isminus(*conv);
		else if (f[i] == '*')
			*conv = ft_isstar(f, *conv, arg, i);
		else if (ft_strchr("cspdiuxX%", f[i]))
		{
			conv->type = f[i];
			break ;
		}
		i++;
	}
	return (i);
}

static int		ft_printarg(va_list arg, t_conv conv)
{
	int		ret;

	ret = 0;
	if (conv.type == 'c')
		ret = ft_printc(va_arg(arg, int), conv);
	else if (conv.type == 's')
		ret = ft_prints(va_arg(arg, char *), conv);
	else if (conv.type == 'p')
		ret = ft_printp(va_arg(arg, long long), conv);
	else if (conv.type == 'd' || conv.type == 'i')
		ret = ft_printi(va_arg(arg, int), conv);
	else if (conv.type == 'u')
		ret = ft_printu(va_arg(arg, int), conv);
	else if (conv.type == 'x' || conv.type == 'X')
		ret = ft_printx(va_arg(arg, int), conv);
	else if (conv.type == '%')
		ret = ft_printprcnt(conv);
	return (ret);
}

int				ft_printf(const char *f, ...)
{
	va_list	arg;
	t_conv	conv;
	int		i;
	int		ret;

	va_start(arg, f);
	i = 0;
	ret = 0;
	while (f[i])
	{
		conv = ft_init_conv(conv);
		if (f[i] == '%' && f[i + 1])
		{
			i++;
			i = ft_parsing(f, &conv, arg, i);
			ret += ft_printarg(arg, conv);
		}
		if (f[i] != '%' && conv.type == 0)
			ret += ft_putchar_r(f[i]);
		i++;
	}
	va_end(arg);
	return (ret);
}
