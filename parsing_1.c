/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemcha <mchemcha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 12:39:37 by mchemcha          #+#    #+#             */
/*   Updated: 2024/03/16 16:21:24 by mchemcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_empty(char *s)
{
	if (s[0] == '\0')
		ft_error("Error");
	return (1);
}

// int	ft_isdigit(int c)
// {
// 	if (c >= '0' && c <= '9')
// 		return (1);
// 	return (0);
// }

int	check_space(char *s)
{
	int	i;

	i = 0;
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

static int	compare_int(char *a, char *b)
{
	if (ft_atoi(a) == ft_atoi(b))
		return (0);
	return (1);
}

int	check_dubl(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if (!compare_int(tab[i], tab[j]))
				return (0);
			else
				j++;
		}
		i++;
	}
	return (1);
}
