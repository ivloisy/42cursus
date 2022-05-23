/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 17:24:22 by ivloisy           #+#    #+#             */
/*   Updated: 2021/10/25 13:36:41 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_ps	ps;

	ft_bzero(&ps, sizeof(ps));
	parsing(ac, av, &ps);
	simplification(&ps);
	sort(&ps);
	exit_error(&ps, EXIT_SUCCESS);
}
