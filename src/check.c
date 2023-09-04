/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:49:20 by fborroto          #+#    #+#             */
/*   Updated: 2023/09/04 14:58:20 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_arg(char **argv)
{
	int		i;
	long	j;

	i = 1;
	while (argv[i])
	{
		j = ft_atoi(argv[i]);
		if (j <= -2147483649 || j >= 2147483648)
		{
			ft_error("Error: element is not an int\n");
		}
		i++;
	}
}

void	ft_check_double(t_stack *a)
{
	int		value;
	t_stack	*tmp;

	tmp = a;
	while (a->next != NULL)
	{
		tmp = a->next;
		while (tmp != NULL)
		{
			if (a->value == tmp->value)
				ft_error("Error: Found a number multiple times\n");
			tmp = tmp->next;
		}
		a = a->next;
	}
}
