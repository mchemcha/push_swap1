/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:27:09 by mchemcha          #+#    #+#             */
/*   Updated: 2024/03/19 23:28:36 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// #include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_stack
{
	int				content;
	int				index;
	int				lis;
	int				position;
	int				t_p;
	int				cost;
	int				t_cost;
	int				total;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

# ifndef BUFFER_SIZE 
#  define BUFFER_SIZE 10
# endif

char		*ft_strdup(const char *s1);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin1(int ac, char  **av);
char		*ft_strjoin(char *s1, char *s2);
char		**ft_split(char *s, char c);
int			ft_strlen(const char *str);
void		*ft_calloc(size_t count, size_t size);
t_stack		*to_list(int *tab, int len);
int			check_min_max(char **tab);
int			check_dubl(char **tab);
int			check_int(char **tab);
int			ft_atoi(char *str);
void		parcing(t_stack **list, char **tab);
int			ft_isdigit(int c);
int			check_space(char *s);
int			check_empty(char *s);
void		ft_error(char *str);
t_stack		*ft_lstlast(t_stack *lst);
void		ft_lstadd_front(t_stack **lst, t_stack *newlst);
void		ft_lstadd_back(t_stack **lst, t_stack *newlst);
t_stack		*ft_lstnew(int content);
int			ft_lstsize(t_stack *lst);
void		s_a(t_stack **stack_a, int i);
void		r_a(t_stack **stack_a, int i);
void		r_b(t_stack **stack_a, int i);
void		s_s(t_stack **stack_a, t_stack **stack_b,int i);
void		r_r(t_stack **stack_a, t_stack **stack_b, int i);
void		s_b(t_stack **stack_a, int i);
void		r_r_a(t_stack **stack_a, int i);
void		r_r_r(t_stack **stack_a, t_stack **stack_b, int i);
void		p_a(t_stack **stack_a, t_stack **stack_b, int i);
void		p_b(t_stack **stack_a, t_stack **stack_b, int i);
void		r_r_b(t_stack **stack_a, int i);
void		printf_lst_prev(t_stack *list);
void		printf_lst_next(t_stack *list);
int			longest_Increasing_Subsequence(t_stack *lis, int i);
int			index_list(t_stack *list, int mark);
void		sort_list(t_stack *list);
// int			l_i_s(t_stack *list);
void		push_to_b(t_stack **list, t_stack **stack_b);
void		target_position(t_stack *stack_a, t_stack *stack_b);
void		positionlist(t_stack *list);
void		cost(t_stack *stack_a);
void		target_cost(t_stack *stack_a, t_stack *stack_b);
void		sort_2(t_stack **list);
void		sort_3(t_stack **list);
void		sort_4(t_stack **list, t_stack **stack_b);
void		sort_5(t_stack **list, t_stack **stack_b);
void		total_cost(t_stack *stack_a);
t_stack		*min_list(t_stack *list);
t_stack		*min_total_cost_list(t_stack *list);
void		best_move(t_stack **list, t_stack **stack_b);
void		get_finel(t_stack **list);
int			ab(int n);
void 		lst_clear(t_stack **list);
long long	ft_atoi_2(char *str);

char	**erreur(char **tab);
char	*ft_read_line(char *s);
char	*ft_read_afterline(char *s);
char	*get_next_line(int fd);
size_t	ft_strlen2(const char *str);
char	*ft_strchr(const char *s, int c);
t_stack	*if_instraction(t_stack **list, t_stack **stack_b);
void	check_list_sort(t_stack *list);
void	instraction(char *read,t_stack **list, t_stack **stack_b);
#endif