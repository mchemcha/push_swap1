/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 12:39:37 by mchemcha          #+#    #+#             */
/*   Updated: 2024/03/11 18:41:05 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_empty(char *s)
{
    if (s[0] == '\0')
        ft_error("Error");
    return (1);
}
int check_int(char **tab)
{
    int i = 0;
    int j;
    while (tab[i])
    {
        j = 0;
        if (tab[i][j] == '-' || tab[i][j] == '+')
            j++;
        while (tab[i][j])
        {
            if (ft_isdigit(tab[i][j]))
                j++;
            else
                return (0);
        }
        i++;
    }
    return (1);
}
int check_space(char *s)
{
    int i = 0;

    if (s[i] == '-' || s[i] == '+')
        i++;

    if (s[0] == ' ')
    {
        while (s[i] == ' ')
            i++;
        if (s[i] == '\0')
            ft_error("Error");
    }
    while (s[i])
    {
        if (ft_isdigit(s[i]) || s[i] == '-' || s[i] == '+')
            i++;
        else if (s[i] != ' ')
            ft_error("Error");
        else
            return (1);
    }
    return (1);
}
int check_min_max(char **tab)
{
    int i = 0;
    while(tab[i])
    {
        if(ft_atoi(tab[i]) > INT_MAX || ft_atoi(tab[i]) < INT_MIN)
            return(0);
        i++;
    }
    return (1);
}
int compare_int(int a, int b)
{
    if (a == b)
        return (0);
    return (1);
}
int check_dubl(char **tab)
{
    int i = 0;
    int j ;
    
    while(tab[i])
    {
        j = i + 1;
        while(tab[j])
        {
            if(!compare_int(*tab[i] , *tab[j]))
                return(0);
            else 
                j++;
        }
        i++;
    }
    return (1);
}
// int check_dubl(int *numbs, int len)
// {
//     int i = 0;
//     int j;
//     while (i < len)
//     {
//         j = i + 1;
//         while (j < len)
//         {
//             if (!compare_int(numbs[i], numbs[j]))
//                 return (0);
//             else
//                 j++;
//         }
//         i++;
//     }
//     return (1);
// }
// t_stack *parcing(char **tab)
// {
//     t_stack *list;
//     int *nums;

//     nums = malloc(ft_strlen(*tab) * sizeof(int));
//     // if (!check_int(tab))
//     //     ft_error("Error");
//     int j = 0;
//     list = NULL;
//     while (tab[j])
//     {
//         nums[j] = atoi(tab[j]);
//         // if (!list)
//         // {
//         //     list = ft_lstnew(nums[j]);
//         // }
//         // else
//             ft_lstadd_back(&list, ft_lstnew(nums[j]));
//         printf("first%d\n", list->content);
//         j++;
//     }
//     // if(!check_dubl(nums, j))
//     //     ft_error("Error");
//     // list = to_list(nums, j);
//     printf_lst_next(list);
    
//     return (list);
// }


void parcing(t_stack **list, char **tab)
{

    int i = 0;
    if(!check_min_max(tab) || !check_dubl(tab))
        ft_error("Eroor");
    while(tab[i])
    {
         ft_lstadd_back(list, ft_lstnew(ft_atoi(tab[i])));
         i++;
    }
}

