/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 12:08:07 by ivloisy           #+#    #+#             */
/*   Updated: 2021/10/25 13:33:59 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_dupli(t_ps *ps)
{
	t_list	*i;
	t_list	*j;

	i = ps->a.lst;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (*(int *)i->content == *(int *)j->content)
				exit_error(ps, EXIT_FAILURE);
			j = j->next;
		}
		i = i->next;
	}
}

void	check_sort(t_ps *ps)
{
	t_list	*i;
	t_list	*j;

	i = ps->a.lst;
	j = i->next;
	while (j)
	{
		if (*(int *)i->content > *(int *)j->content)
			return ;
		i = i->next;
		j = j->next;
	}
	exit_error(ps, EXIT_SUCCESS);
}
