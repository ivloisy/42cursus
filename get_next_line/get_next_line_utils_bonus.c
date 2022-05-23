/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 05:36:48 by ivloisy           #+#    #+#             */
/*   Updated: 2020/03/03 20:58:05 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t		slen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char		*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	l;
	char	*s2;

	i = 0;
	l = 0;
	while (s1[l])
		l++;
	s2 = (char *)malloc(sizeof(char) * (l + 1));
	if (s2 == NULL)
		return (NULL);
	while (i < l)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*join;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	if (!s1 && !s2)
		return (NULL);
	i = 0;
	if (!(join = (char *)malloc(sizeof(char) * (slen(s1) + slen(s2) + 1))))
		return (NULL);
	while (s1[i] != '\0')
	{
		join[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		join[i + slen(s1)] = s2[i];
		i++;
	}
	join[i + slen(s1)] = '\0';
	return (join);
}

char		*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != c)
	{
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)&s[i]);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	i = 0;
	if (!s)
		return (NULL);
	if (start > slen(s))
		len = 0;
	if (!(sub = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (len != 0)
	{
		while (s[start + i] != '\0' && i < len)
		{
			sub[i] = s[start + i];
			i++;
		}
	}
	sub[i] = '\0';
	return (sub);
}
