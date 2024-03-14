/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:41:15 by mchemcha          #+#    #+#             */
/*   Updated: 2024/03/13 23:23:19 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void best_move(t_stack **list,t_stack **stack_b)
{
    //   int s_a = ft_lstsize(*list);
    int s_b = ft_lstsize(*stack_b);
    int i = 0;
	int j = 0;
	t_stack *best_move;
    if(ft_lstsize(*list) == 2)
		sort_2(list);
    else if(ft_lstsize(*list) == 3)
		sort_3(list);
    else if(ft_lstsize(*list) == 4)
		sort_4(list,stack_b);
    else if(ft_lstsize(*list) == 5)
		sort_5(list, stack_b);
    else
	{
		push_to_b(list, stack_b);
        while(j < s_b)
        {
			positionlist(*list);
			positionlist(*stack_b);
			target_position(*list,*stack_b);
			cost(*list);
			cost(*stack_b);
			target_cost(*list, *stack_b);
			total_cost(*stack_b);
			best_move = min_total_cost_list(*stack_b);
			printf("%d\n", best_move->t_cost);
			if(best_move->cost > 0)
			{
				while(i < best_move->cost)
				{
					r_a(list, 1);
					i++;
				}
			}
			if(best_move->cost < 0)
			{
				while(i < best_move->cost)
				{
					r_r_a(list, 1);
					i++;
				}
			}
			if(best_move->t_cost < 0)
			{
				while(i < best_move->t_cost)
				{
					r_r_a(list, 1);
					i++;
				}
			}
			if(best_move->t_cost < 0)
			{
				while(i < (best_move->t_cost)*(-1))
				{
					r_r_a(list, 1);
					i++;
				}
			}
			j++;
		}
	}
}