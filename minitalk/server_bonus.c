/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 15:40:44 by ivloisy           #+#    #+#             */
/*   Updated: 2021/10/19 14:16:53 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static t_sig	g_sig;

static void	get_signal(int n)
{
	g_sig.c += ((n & 1) << g_sig.bit);
	g_sig.bit++;
	if (g_sig.bit == 15)
	{
		if (!g_sig.c)
		{
			g_sig.str[g_sig.i] = '\0';
			write(1, g_sig.str, g_sig.i);
			g_sig.i = -1;
			ft_bzero(g_sig.str, sizeof(g_sig.str));
		}
		g_sig.str[g_sig.i] = g_sig.c;
		g_sig.i++;
		if (g_sig.i == BUFFER_SIZE)
		{
			g_sig.str[g_sig.i] = '\0';
			write(1, g_sig.str, BUFFER_SIZE);
			g_sig.i = 0;
		}
		g_sig.c = 0;
		g_sig.bit = 0;
	}
}

int	main(void)
{
	g_sig.c = 0;
	g_sig.bit = 0;
	g_sig.i = 0;
	ft_putstr_fd("PID : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	while (1)
	{
		signal(SIGUSR1, get_signal);
		signal(SIGUSR2, get_signal);
		pause();
	}
	exit(EXIT_SUCCESS);
}
