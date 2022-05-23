/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 18:18:10 by ivloisy           #+#    #+#             */
/*   Updated: 2020/04/09 18:18:13 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_len(unsigned int n, int base)
{
	int		l;
	long	nb;

	l = 0;
	nb = n;
	if (n < 0)
	{
		l++;
		nb = n * -1;
	}
	while (nb / base)
	{
		l++;
		nb = nb / base;
	}
	l++;
	return (l);
}

static char	*ft_str(unsigned int n, int l, char *s, int base)
{
	long	nb;
	int		neg;
	char	*list;

	nb = n;
	neg = 0;
	list = "0123456789abcdef";
	if (nb < 0)
	{
		neg = 1;
		nb = nb * -1;
	}
	while (l > 0)
	{
		s[l] = list[nb % base];
		nb = nb / base;
		l--;
	}
	if (neg)
		s[l] = '-';
	else
		s[l] = list[nb % base];
	return (s);
}

char		*ft_utoa_base(unsigned int n, int base)
{
	int		l;
	char	*res;

	if (base < 2 || base > 16)
		return (0);
	l = ft_len(n, base);
	res = (char *)malloc(sizeof(char) * (l + 1));
	if (res == NULL)
		return (NULL);
	res = ft_str(n, l - 1, res, base);
	res[l] = '\0';
	return (res);
}
