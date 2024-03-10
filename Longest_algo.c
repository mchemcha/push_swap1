/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Longest_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 17:50:13 by mchemcha          #+#    #+#             */
/*   Updated: 2024/03/10 18:33:57 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_to_b(t_stack **list, t_stack **stack_b)
{
	// sort_list(l*ist);

    // int l_is = l_i_s(*list);
    int lis = longest_Increasing_Subsequence(*list,1);
    sort_list(*list);
    int pivot = ft_lstsize(*list) / 2;
    
    while(ft_lstsize(*list) > lis)
    {
        if((*list)->lis == 0)
        {
            p_b(list, stack_b, 0);
            if ((*stack_b)->index > pivot)
                r_a(stack_b,0);
        }
        else 
            r_a(list,0);
    }
    puts("a===");
	printf_lst_next(*list);
    puts("stack_b===");
	printf_lst_next(*stack_b);
}

// void push_to_a(t_stack **stack_a,t_stack **stack_b)
// {
//     int size = ft_lstsize(*stack_a);
//     positionlist(*stack_a);
//     int m = max_list(*stack_a).position;
//     // int node = max_list(*stack_a).content;
//     // printf("\n####max pos%d #### %d\n", m, node);
//     // printf("\nsize>>%d\n",size/2);
    
//     // while(stack_b)
//     // {}
//         if(m <= (size/2))
//         {
//             while(1)
//             {
//                 if(max_list(*stack_b).position == 0)
//                     break;
//                 r_a(stack_b,1);
//                 positionlist(*stack_b);
//             }
//             p_b(stack_a,stack_b,1);
//         }
    
// }
