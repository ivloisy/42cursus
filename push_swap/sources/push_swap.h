/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:25:04 by ivloisy           #+#    #+#             */
/*   Updated: 2021/10/25 13:33:17 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>

typedef struct s_stack
{
	char	id;
	t_list	*lst;
}t_stack;

typedef struct s_ps
{
	int		l;
	t_stack	a;
	t_stack	b;
}t_ps;

void	parsing(int ac, char **av, t_ps *ps);
void	check_dupli(t_ps *ps);
void	check_sort(t_ps *ps);
void	simplification(t_ps *ps);
void	sort(t_ps *ps);
void	swap(t_ps *ps, int stack);
void	push(t_ps *ps, int stack);
void	rotate(t_ps *ps, int stack);
void	reverse_rotate(t_ps *ps, int stack);
void	protect_malloc(t_ps *ps, void *x);
void	ft_free(void *x);
void	exit_error(t_ps *ps, int x);

#endif
