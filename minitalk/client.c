/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 11:26:37 by ivloisy           #+#    #+#             */
/*   Updated: 2021/10/19 14:12:35 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	is_good_pid(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_isdigit(s[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

static int	send_string(int pid, char *s)
{
	size_t	i;
	int		j;

	i = 0;
	while (i <= ft_strlen(s))
	{
		j = 0;
		while (j < 7)
		{
			if ((s[i] >> j) & 1)
			{
				if (kill(pid, SIGUSR2) < 0)
					return (1);
			}
			else
			{
				if (kill(pid, SIGUSR1) < 0)
					return (1);
			}
			j++;
			usleep(100);
		}
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac == 3)
	{
		if (is_good_pid(av[1]))
			pid = ft_atoi(av[1]);
		if (!is_good_pid(av[1]) || pid == 0)
			exit(EXIT_FAILURE);
		if (send_string(pid, av[2]))
			exit(EXIT_FAILURE);
	}
	else
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}
