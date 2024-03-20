/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 19:04:02 by mchemcha          #+#    #+#             */
/*   Updated: 2024/03/20 10:10:50 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

// void ss()
// {
// 	// atexit(ss);
// 	system("leaks push_swap");
// }

int	main(int ac, char *av[])
{
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
	s = ft_strjoin1(ac, av);
	tab = ft_split(s, ' ');
	free(s);
	parcing(&list, tab);
	erreur(tab);
	best_move(&list, &stack_b);
	lst_clear(&list);
}
