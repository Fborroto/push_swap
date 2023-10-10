/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:15:03 by fborroto          #+#    #+#             */
/*   Updated: 2023/09/22 18:27:26 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

void	ft_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i ++;
	write(2, str, i);
	exit(0);
}

long	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	if (str[i] == '-' && str[i + 1] != '-')
	{
		sign = -1;
		i++;
	}
	if (str[i] == '\0')
		return (2147483649);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (2147483649);
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}

void	decrease_index(t_stack **stack)
{
	t_stack	*tmp;

	tmp = (*stack);
	while (tmp != NULL)
	{
		tmp->index = tmp->index - 1;
		tmp = tmp->next;
	}
}

void	increase_index(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack)
		return ;
	tmp = (*stack);
	while (tmp != NULL)
	{
		tmp->index = tmp->index + 1;
		tmp = tmp->next;
	}
}
