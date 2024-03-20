/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:30:13 by mchemcha          #+#    #+#             */
/*   Updated: 2024/03/20 14:56:13 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		i;
	char	**tab;
	char	*s;
	t_stack	*list;
	t_stack	*stack_b;

	stack_b = NULL;
	if (ac < 2)
		exit(1);
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
	list = if_instraction(&list, &stack_b);
	check_list_sort(list);
	lst_clear(&list);
}

int	compar(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
		{
			return (0);
			break ;
		}
	}
	return (1);
}

void	instraction(char *read, t_stack **list, t_stack **stack_b)
{
	if (compar(read, "ra\n"))
		r_a(list, 0);
	else if (compar(read, "rb\n"))
		r_b(stack_b, 0);
	else if (compar(read, "rr\n"))
		r_r(list, stack_b, 0);
	else if (compar(read, "rra\n"))
		r_r_a(list, 0);
	else if (compar(read, "rrb\n"))
		r_r_b(list, 0);
	else if (compar(read, "rrr\n"))
		r_r_r(list, stack_b, 0);
	else if (compar(read, "sa\n"))
		s_a(list, 0);
	else if (compar(read, "sb\n"))
		s_b(list, 0);
	else if (compar(read, "ss\n"))
		s_s(list, stack_b, 0);
	else if (compar(read, "pb\n"))
		p_b(list, stack_b, 0);
	else if (compar(read, "pa\n"))
		p_a(list, stack_b, 0);
	else
		ft_error("Error");
}

t_stack	*if_instraction(t_stack **list, t_stack **stack_b)
{
	char	*read;

	read = get_next_line(0);
	while (read)
	{
		instraction(read, list, stack_b);
		free(read);
		read = get_next_line(0);
	}
	if ((*stack_b) || !(*list))
		ft_error("KO");
	return (*list);
}

void	check_list_sort(t_stack *list)
{
	int		i;
	t_stack	*last;
	t_stack	*compar;
	t_stack	*first;

	compar = list->next;
	first = list;
	last = ft_lstlast(list);
	i = 0;
	while (compar)
	{
		if (first == last)
			break ;
		if (first->c < compar->c)
		{
			first = first->next;
			compar = compar->next;
		}
		else
			ft_error("KO");
	}
	ft_error("OK");
}
