/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 19:45:52 by mchemcha          #+#    #+#             */
/*   Updated: 2024/03/12 14:21:52 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

void target_position(t_stack *stack_a, t_stack *stack_b)
{
    int closest_biggest;
    int s_a ;

    s_a = ft_lstsize(stack_a);
    positionlist(stack_a);
    positionlist(stack_b);
    int j;
    while (stack_b->t_p == -1)
    {
        j = 0;
        closest_biggest = INT_MAX;
        while (j < s_a)
        {
            if (stack_b->index < stack_a->index && stack_a->index < closest_biggest)
            {
                closest_biggest = stack_a->index;
                stack_b->t_p = stack_a->position;
            }
            stack_a = stack_a->next;
            j++;
        }
        stack_b = stack_b->next;
    }
}
void cost(t_stack *stack_a)
{
	int size = ft_lstsize(stack_a);
	int pm = ft_lstsize(stack_a) / 2;
	int i = 0;
	positionlist(stack_a);
	while(i < size)
	{
			printf("|%d| position ====%d\n", stack_a->content, stack_a->position);
			if(stack_a->position <= pm)
			{
				stack_a->cost = stack_a->position;
			}
			else if(stack_a->position > pm)
			{
				stack_a->cost = (size - stack_a->position)*(-1);
			}
		stack_a = stack_a->next;
		i++;
	}
}
void target_cost(t_stack *stack_a ,t_stack *stack_b)
{
	int closest_biggest;
    int s_a ;
    int s_b = ft_lstsize(stack_b) ;

    s_a = ft_lstsize(stack_a);
    positionlist(stack_a);
    positionlist(stack_b);
    int i=0;
    int j;
    while (i < s_b)
    {
        j = 0;
        closest_biggest = INT_MAX;
        while (j < s_a)
        {
            if (stack_b->index < stack_a->index && stack_a->index < closest_biggest)
            {
                closest_biggest = stack_a->index;
                stack_b->t_cost = stack_a->cost;
            }
            stack_a = stack_a->next;
            j++;
        }
        stack_b = stack_b->next;
		i++;
    }
	
}
