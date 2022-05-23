/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 05:04:10 by ivloisy           #+#    #+#             */
/*   Updated: 2019/11/14 23:25:03 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*protect_null(const char *s1, const char *s2)
{
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	return (NULL);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*join;

	if (!s1 && !s2)
		return (NULL);
	if ((join = protect_null(s1, s2)))
		return (join);
	i = 0;
	join = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (join == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		join[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		join[i + ft_strlen(s1)] = s2[i];
		i++;
	}
	join[i + ft_strlen(s1)] = '\0';
	return (join);
}
