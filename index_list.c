/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:10:35 by mchemcha          #+#    #+#             */
/*   Updated: 2024/03/13 13:49:20 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_list(t_stack *list)
{
    int i;
    t_stack *first = list;
    t_stack *tmp = list;
    int s;
    int size = ft_lstsize(list);

    i=0;

    while(size--)
    {
        s = ft_lstsize(list);
        i=0;
        while(s--)
        {

            if(first->content < tmp->content)  
                i++;
            first = first->next;
        }
        tmp->index = i;
        tmp = tmp->next; 
    }
}
void positionlist(t_stack *list)
{
    int size = ft_lstsize(list);
    int i = 0;
    while(size--)
    {
        list->position = i;
        i++;
        list =list ->next;
    }
}
// t_stack max_list(t_stack *list)
// {
//     t_stack *max_node;
//     int size = ft_lstsize(list);
//     int max = 0;
//     while(size)
//     {
//         if(list->content > max)
//         {   
//             max = list->content;
//             max_node=list;
//         }
//         list = list->next;
//         size--;
//     }
//     return(*max_node);
// }
t_stack *min_list(t_stack *list)
{
     t_stack *min_node;
    int size = ft_lstsize(list);
    int min = INT_MAX;
    positionlist(list);
    while(size)
    {
        if(list->index < min)
        {   
            min = list->index;
            min_node=list;
        }
        list = list->next;
        size--;
    }
    return (min_node);
}
t_stack *min_total_cost_list(t_stack *list)
{
     t_stack *min_node;
    int size = ft_lstsize(list);
    int min = INT_MAX;
    positionlist(list);
    while(size)
    {
        if(list->total < min)
        {   
            min = list->total;
            min_node=list;
        }
        list = list->next;
        size--;
    }
    return (min_node);
}
int index_list(t_stack *list, int mark)
{

    int i;
    t_stack *cont = list;
    t_stack *last = ft_lstlast(list);
    t_stack *compar = list ;
    i = 0;
    
    while (compar)
    {
        compar -> index = 0;
        if(compar -> content >= cont -> content)
        {
            cont = compar;
            if (mark)
                cont->lis= 1;
            i++;
        }
        if (compar == last)
            break;
        compar = compar -> next;
    }
    return(i);
}
int longest_Increasing_Subsequence(t_stack *list, int mark)
{
    t_stack *tmp = list;
    t_stack *tmp2 = list;

    int i = 0;
    int j;
    
    while(tmp)
    {
        j = index_list(tmp, 0);
        if(j>i)
        {
            i = j;
            tmp2 = tmp;
        }
        tmp = tmp->next;
        if(tmp == list)
            break;
    }
    if(mark == 1)
        index_list(tmp2,1);
    return (i);
}

