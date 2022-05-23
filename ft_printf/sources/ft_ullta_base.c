/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ullta_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 18:17:43 by ivloisy           #+#    #+#             */
/*   Updated: 2020/04/09 18:17:45 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_len(unsigned long long n, int base)
{
	int		l;

	l = 0;
	if (n < 0)
	{
		l++;
		n = n * -1;
	}
	while (n / base)
	{
		l++;
		n = n / base;
	}
	l++;
	return (l);
}

static char	*ft_str(unsigned long long n, int l, char *s, int base)
{
	int		neg;
	char	*list;

	neg = 0;
	list = "0123456789abcdef";
	if (n < 0)
	{
		neg = 1;
		n = n * -1;
	}
	while (l > 0)
	{
		s[l] = list[n % base];
		n = n / base;
		l--;
	}
	if (neg)
		s[l] = '-';
	else
		s[l] = list[n % base];
	return (s);
}

char		*ft_ulltoa_base(unsigned long long n, int base)
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
