/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_4_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 15:30:30 by mchemcha          #+#    #+#             */
/*   Updated: 2024/03/11 20:16:05 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void sort_3(t_stack **list)
// {

//     if ((*list)->content > (*list)->next->content
//      && (*list)->next->content < (*list)->prev->content 
//      && (*list)->content < (*list)->prev->content)
//         s_a(list, 1);
//     else if((*list)->content > (*list)->next->content 
//     && (*list)->next->content > (*list)->prev->content 
//     && (*list)->content > (*list)->prev->content)
//     {
//         s_a(list, 1);
//         r_r_a(list,1);
//     }
//     else if((*list)->content > (*list)->next->content 
//     && (*list)->next->content < (*list)->prev->content 
//     && (*list)->content > (*list)->prev->content)
//         r_a(list, 1);
//     else if((*list)->content < (*list)->next->content 
//     && (*list)->next->content > (*list)->prev->content 
//     && (*list)->content < (*list)->prev->content)
//     {
//         s_a(list,1);
//         r_a(list, 1);
//     }
//     else if((*list)->content < (*list)->next->content 
//     && (*list)->next->content > (*list)->prev->content 
//     && (*list)->content > (*list)->prev->content)
//         r_r_a(list, 1);
// }