/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 15:14:58 by ivloisy           #+#    #+#             */
/*   Updated: 2021/11/18 04:03:22 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static void	sleeping(t_ph *ph)
{
	if (!check_stop(ph))
		wait_until(ph->arg->time_to_eat);
	if (ph->id % 2 == 0)
		pthread_mutex_unlock(ph->r_fork);
	else
		pthread_mutex_unlock(ph->l_fork);
	if (ph->id % 2 == 0)
		pthread_mutex_unlock(ph->l_fork);
	else
		pthread_mutex_unlock(ph->r_fork);
	if (!check_stop(ph))
		print_status(ph, "is sleeping");
	if (!check_stop(ph))
		wait_until(ph->arg->time_to_sleep);
	if (!check_stop(ph))
		print_status(ph, "is thinking");
}

static void	eat(t_ph *ph)
{
	if (ph->id % 2 == 0 && ph->arg->number_of_philosophers != 1)
		pthread_mutex_lock(ph->r_fork);
	else
		pthread_mutex_lock(ph->l_fork);
	print_status(ph, "has taken a fork");
	if (ph->arg->number_of_philosophers == 1)
	{
		wait_until(ph->arg->time_to_die + 5);
		pthread_mutex_unlock(ph->l_fork);
		return ;
	}
	if (ph->id % 2 == 0)
		pthread_mutex_lock(ph->l_fork);
	else
		pthread_mutex_lock(ph->r_fork);
	print_status(ph, "has taken a fork");
	print_status(ph, "is eating");
	pthread_mutex_lock(&ph->meal);
	ph->last = get_time();
	pthread_mutex_unlock(&ph->meal);
	ph->nb++;
}

static void	say_stop(t_ph *ph)
{
	if (ph->arg->done == ph->arg->number_of_philosophers)
	{
		pthread_mutex_unlock(&ph->arg->rep);
		pthread_mutex_lock(&ph->arg->dead);
		ph->arg->stop = 1;
		pthread_mutex_unlock(&ph->arg->dead);
	}
	else
		pthread_mutex_unlock(&ph->arg->rep);
}

void	*routine(void *philo)
{
	t_ph	*ph;

	ph = (t_ph *)philo;
	if (ph->id % 2 == 0)
		wait_until(ph->arg->time_to_eat / 10);
	while (!check_stop(ph))
	{
		eat(ph);
		if (ph->arg->number_of_times_each_philosopher_must_eat != 0)
		{
			if (ph->nb == ph->arg->number_of_times_each_philosopher_must_eat)
			{
				pthread_mutex_lock(&ph->arg->rep);
				ph->arg->done++;
				say_stop(ph);
			}
		}
		if (ph->arg->number_of_philosophers != 1)
			sleeping(ph);
	}
	return (NULL);
}
