/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:41:15 by mchemcha          #+#    #+#             */
/*   Updated: 2024/03/17 13:55:22 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void best_move(t_stack **list, t_stack **stack_b)
{
	int s_b;
	int j = 0;
	t_stack *best_move;
	if (ft_lstsize(*list) == 2)
		sort_2(list);
	else if (ft_lstsize(*list) == 3)
		sort_3(list);
	else if (ft_lstsize(*list) == 4)
		sort_4(list, stack_b);
	else if (ft_lstsize(*list) == 5)
	{
		sort_5(list, stack_b);
	}
	else
	{
		push_to_b(list, stack_b);
		s_b = ft_lstsize(*stack_b);
		while (j < s_b)
		{
			positionlist(*list);
			positionlist(*stack_b);
			target_position(*list, *stack_b);
			cost(*list);
			cost(*stack_b);
			target_cost(*list, *stack_b);
			total_cost(*stack_b);
			best_move = min_total_cost_list(*stack_b);
			while (best_move->cost > 0 && best_move->t_cost > 0)
			{
				r_r(list, stack_b, 1);
				best_move->cost--;
				best_move->t_cost--;
			}
			while (best_move->cost < 0 && best_move->t_cost < 0)
			{
				r_r_r(list, stack_b, 1);
				best_move->cost++;
				best_move->t_cost++;
			}
			while (best_move->cost > 0)
			{
				r_b(stack_b, 1);
				best_move->cost--;
			}
			while (best_move->cost < 0)
			{
				r_r_b(stack_b, 1);
				best_move->cost++;
			}
			while (best_move->t_cost > 0)
			{
				r_a(list, 1);
				best_move->t_cost--;
			}
			while (best_move->t_cost < 0)
			{
				r_r_a(list, 1);
				best_move->t_cost++;
			}
			p_a(list, stack_b, 1);
			j++;
		}
		get_finel(list);
		// puts("\nstack_a\n");
		// printf_lst_next(*list);
		// puts("\nstack_b\n");
		// printf_lst_next(*stack_b);
		// puts("\n========\n");
	}
}
void get_finel(t_stack **list)
{
	t_stack *min = min_list(*list);
	
	sort_list(*list);
	cost(*list);
	while (min->cost > 0)
	{
		r_a(list, 1);
		min->cost--;
	}
	while (min->cost < 0)
	{
		r_r_a(list, 1);
		min->cost++;
	}
}