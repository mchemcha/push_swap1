/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finel_linked.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 14:01:14 by mchemcha          #+#    #+#             */
/*   Updated: 2024/03/17 16:05:22 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void lst_clear(t_stack **list)
{
	int	s;
	int i = 0;

	s = ft_lstsize((*list));
	while (i < s)
	{
		free((*list));
		(*list)= (*list)->next;
		i++;
	}
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	return (lst ->prev);
}

t_stack	*ft_lstnew(int content)
{
	t_stack	*list;

	list = (t_stack *)malloc(sizeof(t_stack));
	if (list == NULL)
		return (NULL);
	list->index = 0;
	list->t_p = -1;
	list->cost = 0;
	list->position = 0;
	list->t_cost = 0;
	list->total = 0;
	list->content = content;
	list->next = list;
    list->prev = list;                                                                                                                                                                                                              
	return (list);
}
void	ft_lstadd_back(t_stack **lst, t_stack *newlst)
{
	t_stack	*last;
	t_stack	*first;

	if (*lst == NULL)
		*lst = newlst;
	else
	{
		first = *lst;
		last = ft_lstlast(*lst);
		last -> next = newlst;
		newlst -> next = first;
		first->prev=newlst;
		newlst->prev=last;
	}
}
void	ft_lstadd_front(t_stack **lst, t_stack *newlst)
{
	if (*lst == NULL)
		*lst = newlst;
	else
	{
		ft_lstadd_back(lst, newlst);
		*lst = newlst;
	}
}
t_stack *to_list(int *tab, int len)
{
    int i;
    t_stack *list;

	list = NULL;
	i = 0;
    while (i < len)
    {
		t_stack *p = ft_lstnew(tab[i]);
		if (list == NULL)
			list=p;
		else
			ft_lstadd_back(&list, p);
		i++;
	}
	return(list);
}
int	ft_lstsize(t_stack *lst)
{
	t_stack	*i;
	int		s;
	t_stack *last = ft_lstlast(lst);
	s = 1;
	i = lst;
	if (lst == NULL)
		return (0);
	while (i != last && i -> next != NULL)
	{
		s += 1;
		i = i -> next;
	}

	return (s);
}





// failed tests:
// "-" 
// "+" 
// "   -   "
// " -0 0"