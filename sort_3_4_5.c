/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_4_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:30:30 by mchemcha          #+#    #+#             */
/*   Updated: 2024/03/16 13:29:35 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_2(t_stack **list)
{
    if ((*list)->content > (*list)->next->content)
        s_a(list, 1);
}
void sort_3(t_stack **list)
{
    if ((*list)->content > (*list)->next->content && (*list)->next->content < (*list)->prev->content && (*list)->content < (*list)->prev->content)
        s_a(list, 1);
    else if ((*list)->content > (*list)->next->content && (*list)->next->content > (*list)->prev->content && (*list)->content > (*list)->prev->content)
    {
        s_a(list, 1);
        r_r_a(list, 1);
    }
    else if ((*list)->content > (*list)->next->content && (*list)->next->content < (*list)->prev->content && (*list)->content > (*list)->prev->content)
        r_a(list, 1);
    else if ((*list)->content < (*list)->next->content && (*list)->next->content > (*list)->prev->content && (*list)->content < (*list)->prev->content)
    {
        s_a(list, 1);
        r_a(list, 1);
    }
    else if ((*list)->content < (*list)->next->content && (*list)->next->content > (*list)->prev->content && (*list)->content > (*list)->prev->content)
        r_r_a(list, 1);
}

void sort_4(t_stack **list, t_stack **stack_b)
{
    t_stack *min_node;
    sort_list(*list);
    min_node = min_list(*list);
    cost(*list);
    while (min_node->cost > 0)
    {
        r_a(list, 1);
        min_node->cost--;
    }
    while (min_node->cost < 0)
    {
        r_r_a(list, 1);
        min_node->cost++;
    }
    p_b(list, stack_b, 1);
    sort_3(list);
    p_a(list, stack_b, 1);
}
void sort_5(t_stack **list, t_stack **stack_b)
{
    t_stack *min_node;
    sort_list(*list);
    min_node = min_list(*list);
    cost(*list);
    while (min_node->cost > 0)
    {
        r_a(list, 1);
        min_node->cost--;
    }
    while (min_node->cost < 0)
    {
        r_r_a(list, 1);
        min_node->cost++;
    }
    p_b(list, stack_b, 1);
    sort_4(list, stack_b);
    p_a(list, stack_b, 1);
}
