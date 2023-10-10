/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:49:20 by fborroto          #+#    #+#             */
/*   Updated: 2023/10/10 14:06:16 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_int(char **array)
{
	int		i;
	long	j;

	i = 0;
	while (array[i])
	{
		j = ft_atoi(array[i]);
		if (j <= -2147483649 || j >= 2147483648)
		{
			i = 0;
			while (array[i] != NULL)
			{
				free(array[i]);
				i++;
			}
			free(array);
			ft_error("Error: element is not an int\n");
		}
		i++;
	}
}

int	ft_is_quoted(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

void	ft_check_arg(char **argv)
{
	int		i;
	long	j;

	i = 1;
	while (argv[i])
	{
		if (ft_is_quoted(argv[i]))
			i++;
		else
		{
			j = ft_atoi(argv[i]);
			if (j <= -2147483649 || j >= 2147483648)
			{
				ft_error("Error: element is not an int\n");
			}
			i++;
		}
	}
}

void	ft_check_double(t_stack *a, t_stack *b)
{
	t_stack	*tmp;

	tmp = a;
	while (a->next != NULL)
	{
		tmp = a->next;
		while (tmp != NULL)
		{
			if (a->value == tmp->value)
			{
				ft_putstr("Error: Found a number multiple times\n");
				ft_close(&a, &b);
			}
			tmp = tmp->next;
		}
		a = a->next;
	}
}
