/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 19:04:02 by mchemcha          #+#    #+#             */
/*   Updated: 2024/03/16 17:03:38 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void ss()
{
	system("leaks push_swap");
}

int	main(int ac, char *av[])
{
	atexit(ss);
	int		i;
	char	**tab;
	char	*s;
	t_stack	*list;
	t_stack	*stack_b;

	stack_b = NULL;
	if (ac < 2)
		exit (1);
	i = 0;
	while (av[++i])
	{
		check_empty(av[i]);
		check_space(av[i]);
	}
	s = av[1];
	i = 1;
	while (av[++i])
	{
		s = ft_strjoin(s, " ");
		s = ft_strjoin(s, av[i]);
	}
	tab = ft_split(s, ' ');
	parcing(&list, tab);
	best_move(&list, &stack_b);
}
