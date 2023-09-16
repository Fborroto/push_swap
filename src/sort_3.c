/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:47:11 by fborroto          #+#    #+#             */
/*   Updated: 2023/09/16 18:00:15 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*find_highest(t_stack *stack)
{
	int		highest;
	t_stack	*highest_node;

	if (NULL == stack)
		return (NULL);
	highest = INT_MIN;
	while (stack)
	{
		if (stack->value > highest)
		{
			highest = stack->value;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return (highest_node);
}

void	ft_sort3(t_stack **a)
{
	t_stack	*highest_node;

	highest_node = find_highest(*a);
	if (*a == highest_node)
		rotate_n(a, 1);
	else if ((*a)->next == highest_node)
		rotate_rotate_n(a, 1);
	if ((*a)->value > (*a)->next->value)
		swap_n(a, 1);
}
