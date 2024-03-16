/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Longest_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 17:50:13 by mchemcha          #+#    #+#             */
/*   Updated: 2024/03/16 13:47:02 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_stack **list, t_stack **stack_b)
{
	int lis;
	int pivot;

	lis = longest_Increasing_Subsequence(*list, 1);
	sort_list(*list);
	pivot = ft_lstsize(*list) / 2;
	while(ft_lstsize(*list) > lis)
	{
		if((*list)->lis == 0)
		{
			p_b(list, stack_b, 1);
			if ((*stack_b)->index > pivot)
			r_b(stack_b,1);
		}
		else
		r_a(list,1);
	}
}
