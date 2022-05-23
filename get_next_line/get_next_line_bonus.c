/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 05:34:55 by ivloisy           #+#    #+#             */
/*   Updated: 2020/03/03 20:56:30 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	len_line(char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\n' && str[i])
		i++;
	return (i);
}

static int	read_buf(int fd, char **str)
{
	char	*tmp;
	char	buf[BUFFER_SIZE + 1];
	int		ret;

	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(tmp = ft_strjoin((*str), buf)))
		{
			free(tmp);
			tmp = NULL;
			ret = -1;
		}
		free((*str));
		(*str) = tmp;
		if (ft_strchr((*str), '\n'))
			break ;
	}
	return (ret);
}

int			get_next_line(int fd, char **line)
{
	int			ret;
	static char	*str[OPEN_MAX];
	char		*tmp;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || read(fd, NULL, 0) == -1)
		return (-1);
	if (!(ft_strchr(str[fd], '\n')))
	{
		if ((ret = read_buf(fd, &str[fd])) == -1)
			return (-1);
	}
	if (str[fd])
		(*line) = ft_substr(str[fd], 0, len_line(str[fd]));
	else
		(*line) = ft_strdup("");
	if (ft_strchr(str[fd], '\n'))
	{
		tmp = ft_strdup(&str[fd][len_line(str[fd]) + 1]);
		free(str[fd]);
		str[fd] = tmp;
		return (1);
	}
	free(str[fd]);
	str[fd] = NULL;
	return (0);
}
