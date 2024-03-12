/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 19:44:29 by mchemcha          #+#    #+#             */
/*   Updated: 2024/03/11 20:39:15 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void    printf_lst_next(t_stack *list)
{
    t_stack *p;
    // t_stack *last = ft_lstlast(list);
    int s = ft_lstsize(list);
    if (list == NULL)
        return;
    p = list;
    while (s)
    {
         printf("[%d] position :%d idx :%d t_p = %d\n", p->content, p->position,p->index, p->t_p);
         p = p->next;
         s--;
    }
}


void    printf_lst_prev(t_stack *list)
{
    t_stack *head;
    
    head = list;
    while(list)
    {
        printf("%d\n",list->content);
        list = list->prev;
        if(head == list)
            break; 
    }
}
