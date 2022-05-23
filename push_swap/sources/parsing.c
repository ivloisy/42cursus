/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 02:03:31 by ivloisy           #+#    #+#             */
/*   Updated: 2021/10/25 14:59:04 by ivloisy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	add_to_list(t_ps *ps, char *s)
{
	int		*x;
	t_list	*lst;

	x = (int *)malloc(sizeof(int));
	if (x == NULL)
		exit_error(ps, EXIT_FAILURE);
	*x = ft_atoi(s);
	lst = ft_lstnew(x);
	if (lst == NULL)
		exit_error(ps, EXIT_FAILURE);
	ft_lstadd_back(&ps->a.lst, lst);
	free (s);
	s = NULL;
}

static void	check_char(t_ps *ps, char *s, int i)
{
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (ft_isdigit(s[i]))
		i++;
	if (s[i] != '\0' || ft_atol(s) > INT_MAX
		|| ft_atol(s) < INT_MIN)
		exit_error(ps, EXIT_FAILURE);
}

static void	check_arg(int ac, char **av, t_ps *ps)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	j = 0;
	while (++j < ac)
	{
		tab = ft_split(av[j], ' ');
		protect_malloc(ps, tab);
		k = -1;
		while (tab[++k])
		{
			i = 0;
			check_char(ps, tab[k], i);
			add_to_list(ps, tab[k]);
		}
		ft_free(tab);
	}
}

void	parsing(int ac, char **av, t_ps *ps)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	if (ac < 2)
		exit_error(ps, EXIT_SUCCESS);
	while (++i < ac)
	{
		if (av[i][0] == '\0')
			exit_error(ps, EXIT_FAILURE);
		j = 0;
		k = 0;
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]) == 1)
				k = 1;
			j++;
		}
		if (k == 0)
			exit_error(ps, EXIT_FAILURE);
	}
	check_arg(ac, av, ps);
	check_dupli(ps);
	check_sort(ps);
}
