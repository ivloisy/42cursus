/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 03:47:36 by ivloisy           #+#    #+#             */
/*   Updated: 2021/11/18 13:23:16 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	print_status(t_ph *ph, char *s)
{
	long	time;

	time = get_time();
	if (time == -1)
		return (0);
	time = time - ph->arg->start;
	pthread_mutex_lock(&ph->arg->print);
	if (time >= 0 && time <= INT_MAX && !check_stop(ph))
	{
		printf("%ld %d %s\n", time, ph->id, s);
		if (!ft_strncmp("died", s, 4))
		{
			pthread_mutex_lock(&ph->arg->dead);
			ph->arg->stop = 1;
			pthread_mutex_unlock(&ph->arg->dead);
		}
		pthread_mutex_unlock(&ph->arg->print);
	}
	else
		pthread_mutex_unlock(&ph->arg->print);
	return (1);
}

int	check_stop(t_ph *ph)
{
	pthread_mutex_lock(&ph->arg->dead);
	if (ph->arg->stop)
	{
		pthread_mutex_unlock(&ph->arg->dead);
		return (1);
	}
	pthread_mutex_unlock(&ph->arg->dead);
	return (0);
}

static void	check_dead(t_data *data, int *x)
{
	int	i;

	i = -1;
	while (++i < data->arg.number_of_philosophers)
	{
		pthread_mutex_lock(&data->ph[i].meal);
		if ((get_time() - data->ph[i].last) > (long)(data->arg.time_to_die))
		{
			pthread_mutex_unlock(&data->ph[i].meal);
			print_status(&data->ph[i], "died");
			break ;
		}
		pthread_mutex_unlock(&data->ph[i].meal);
	}
	pthread_mutex_lock(&data->arg.dead);
	if (data->arg.stop)
	{
		pthread_mutex_unlock(&data->arg.dead);
		*x = 1;
	}
}

static void	free_data(t_data *data)
{
	free (data->ph);
	data->ph = NULL;
	free (data->arg.fork);
	data->arg.fork = NULL;
}

void	finish(t_data *data)
{
	int	i;
	int	x;

	x = 0;
	while (!x)
	{
		usleep(500);
		check_dead(data, &x);
		if (!x)
			pthread_mutex_unlock(&data->arg.dead);
	}
	i = -1;
	while (++i < data->arg.number_of_philosophers)
		pthread_join(data->ph[i].th, NULL);
	pthread_mutex_destroy(&data->arg.dead);
	pthread_mutex_destroy(&data->arg.rep);
	pthread_mutex_destroy(&data->arg.print);
	i = -1;
	while (++i < data->arg.number_of_philosophers)
	{
		pthread_mutex_destroy(&data->arg.fork[i]);
		pthread_mutex_destroy(&data->ph[i].n);
		pthread_mutex_destroy(&data->ph[i].meal);
	}
	free_data(data);
}
