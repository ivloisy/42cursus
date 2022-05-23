/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 18:16:57 by ivloisy           #+#    #+#             */
/*   Updated: 2020/04/09 18:17:01 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s1)
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
