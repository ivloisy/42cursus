/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 04:09:11 by ivloisy           #+#    #+#             */
/*   Updated: 2021/10/25 13:48:45 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	protect_malloc(t_ps *ps, void *x)
{
	if (x == NULL)
		exit_error(ps, EXIT_FAILURE);
}

void	ft_free(void *x)
{
	free(x);
	x = NULL;
}

static void	free_lst(t_ps *ps)
{
	t_list	*tmp;
	t_list	*lst;

	lst = ps->a.lst;
	while (lst)
	{
		tmp = lst;
		free(tmp->content);
		lst = lst->next;
		free(tmp);
	}
	lst = ps->b.lst;
	while (lst)
	{
		tmp = lst;
		free(tmp->content);
		lst = lst->next;
		free(tmp);
	}
}

void	exit_error(t_ps *ps, int x)
{
	free_lst(ps);
	if (x == EXIT_FAILURE)
		ft_putstr_fd("Error\n", 2);
	exit(x);
}
