/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 23:39:29 by ivloisy           #+#    #+#             */
/*   Updated: 2021/12/01 00:34:14 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab[i]);
	tab[i] = NULL;
	free(tab);
	tab = NULL;
}

static void	free_tp(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
}

static void	free_pos(t_sl *sl)
{
	free(sl->e);
	free(sl->c);
}

void	free_sl(t_sl *sl)
{
	if (sl->map)
		free_tab(sl->map);
	if (sl->tp)
		free_tp(sl->tp);
	if (sl->tex)
		free_tex(sl);
	free_pos(sl);
	free_img(sl, sl->img);
	if (sl->ptr && sl->win)
	{
		mlx_clear_window(sl->ptr, sl->win);
		mlx_destroy_window(sl->ptr, sl->win);
	}
	if (sl->ptr)
	{
		mlx_destroy_display(sl->ptr);
		free(sl->ptr);
	}
}
