/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instraction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 13:28:16 by mchemcha          #+#    #+#             */
/*   Updated: 2024/03/16 15:22:17 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s_a(t_stack **stack_a, int i)
{
	t_stack *a ;
	t_stack *b;
	t_stack *c;
	
	a = *stack_a;
	b = a->next;
	c = a->next->next;
	b->next = b;
	b->prev = b;
	a->next=c;
	c->prev = a;
	ft_lstadd_front(stack_a, b);
	if(i == 1)
		write(1, "sa\n", 3);
}
void s_s(t_stack **stack_a, t_stack **stack_b)
{
	s_a(stack_a, 0);
	s_a(stack_b, 0);	
}

void r_a(t_stack **stack_a,int i)
{
	
	t_stack *b;
	t_stack *first;
	
	first = *stack_a;
	b = first->next;
	*stack_a = b;
	if(i == 1)
		write(1, "ra\n", 3);
}
void r_b(t_stack **stack_a,int i)
{
	
	t_stack *b;
	t_stack *first;
	
	first = *stack_a;
	b = first->next;
	*stack_a = b;
	if(i == 1)
		write(1, "rb\n", 3);
}
void r_r(t_stack **stack_a, t_stack **stack_b, int i)
{
	r_a(stack_a,0);
	r_b(stack_b,0);
	if(i == 1)
		write(1, "rr\n", 3);
}
void r_r_a(t_stack **stack_a, int i)
{
	*stack_a = ft_lstlast(*stack_a);
	if(i == 1)
		write(1, "rra\n", 4);
}
void r_r_b(t_stack **stack_a, int i)
{
	*stack_a = ft_lstlast(*stack_a);
	if(i == 1)
		write(1, "rrb\n", 4);
}
void r_r_r(t_stack **stack_a, t_stack **stack_b,int i)
{
	if(i == 1)
		write(1, "rrr\n", 4);
	r_r_a(stack_a, 0);
	r_r_b(stack_b, 0);
}
void p_b(t_stack **stack_a,t_stack **stack_b, int i)
{
	t_stack *a;
	t_stack *last;
	t_stack *b;
	
	if (!*stack_a)
		return ;
	if(ft_lstsize(*stack_a) == 1)
	{
		t_stack *first = *stack_a;
		ft_lstadd_front(stack_b,first);
		*stack_a = NULL;
		return;
	}
	a = *stack_a;
	last = ft_lstlast(*stack_a);
	b = a->next;
	a->next = a;
	a->prev= a;
	b->prev =last;
	last->next=b;
	ft_lstadd_front(stack_b,a);
	*stack_a=b;
	if(i == 1)
		write(1, "pb\n", 3);
}

void  p_a(t_stack **stack_a,t_stack **stack_b, int i)
{
	
	t_stack *a;
	t_stack *last;
	t_stack *b;
	(void)i;
	if (!*stack_b)
		return ;
	if(i == 1)
		write(1, "pa\n", 3);
	if(ft_lstsize(*stack_b) == 1)
	{
		t_stack *first = *stack_b;
		ft_lstadd_front(stack_a,first);
		*stack_b = NULL;
		return;
	}
	a = *stack_b;
	
	last = ft_lstlast(*stack_b);
	b = a->next;
	a->next =a;
	a->prev=a;
	b->prev =last;
	last->next=b;
	ft_lstadd_front(stack_a,a);
	*stack_b=b;
}

