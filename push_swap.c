/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 19:04:02 by mchemcha          #+#    #+#             */
/*   Updated: 2024/03/11 20:22:42 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

int	main(int ac, char *av[])
{
	int		i;
	t_stack	*list;
	char	**tab;
	char	*s;
	t_stack *stack_b = NULL;
	
	if (ac < 2)
		exit (1);
	i = 0;
	while(av[++i])
	{
		check_empty(av[i]);
		check_space(av[i]);
	}
	
	// char **sp = ft_split(av[i], ' ');
	s = av[1];
	i = 1;
	while(av[++i])
	{
		s = ft_strjoin(s, " ");
		s = ft_strjoin(s, av[i]);
	}
	tab = ft_split(s, ' ');
	if (!check_int(tab))
		ft_error("Error");
	parcing(&list, tab);
	// list = parcing(tab);
	push_to_b(&list, &stack_b);
	puts("a===");
	printf_lst_next(list);
	puts("stack_b===");
	printf_lst_next(stack_b);
	puts("\n========\n");
    // positionlist(list);
	target_position(list,stack_b);
	puts("a===");
	printf_lst_next(list);
	puts("stack_b===");
	printf_lst_next(stack_b);
	
	// printf("max is>>>%d>>>>%d", max_list(list).position,max_list(list).content);
	//t_stack *head ;
	// head = longest_Increasing_Subsequence(list,1);
	// // push_to_b(list,stack_b);
	// // puts("######\n");
	// // printf("---%d--\n",head->content);
	// // printf("---%d--\n",l_i_s(list));
	// push_to_b(&list, &stack_b);
	// // s_a(&list);
	// sort_list(list);
	// puts("befor a===");
	// printf_lst_next(list);
	// push_to_a(&list,&stack_b);
	
}
