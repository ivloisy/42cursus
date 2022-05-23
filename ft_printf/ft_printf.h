/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 18:00:38 by ivloisy           #+#    #+#             */
/*   Updated: 2020/04/09 18:00:41 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# include "./includes/libft.h"

typedef struct	s_conv
{
	int		width;
	int		prec;
	int		minus;
	int		zero;
	int		dot;
	int		star;
	int		type;
}				t_conv;

int				ft_printf(const char *format, ...);
int				ft_putchar_r(char c);
int				ft_putstr_r(char *s);
int				ft_printc(char c, t_conv conv);
int				ft_prints(char *s, t_conv conv);
int				ft_printp(long long p, t_conv conv);
int				ft_printi(int n, t_conv conv);
int				ft_printu(int n, t_conv conv);
int				ft_printx(int n, t_conv conv);
int				ft_printprcnt(t_conv conv);
t_conv			ft_isnum(const char *f, t_conv conv, int i);
int				ft_isdot(const char *f, t_conv *conv, int i);
t_conv			ft_isminus(t_conv conv);
t_conv			ft_isstar(const char *f, t_conv conv, va_list arg, int i);
char			*ft_utoa(unsigned int n);
char			*ft_utoa_base(unsigned int n, int base);
char			*ft_ulltoa_base(unsigned long long n, int base);

#endif
