/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:22:10 by fborroto          #+#    #+#             */
/*   Updated: 2023/09/22 14:59:32 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*return_cheapest(t_stack *stack)
{
	if (NULL == stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	set_cheapest(t_stack *b)
{
	long	best_match_value;
	t_stack	*best_match_node;

	if (NULL == b)
		return ;
	best_match_value = LONG_MAX;
	while (b)
	{
		if (b->price < best_match_value)
		{
			best_match_value = b->price;
			best_match_node = b;
		}
		b = b->next;
	}
	best_match_node->cheapest = true;
}

void	set_price(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = ft_list_len(a) + 1;
	len_b = ft_list_len(b) + 1;
	while (b)
	{
		b->price = b->index;
		if (!(b->above_median))
		{
			b->price = len_b - (b->index);
		}
		if (b->target_node->above_median)
		{
			b->price += b->target_node->index;
		}
		else
		{
			b->price += len_a - (b->target_node->index);
		}
		b = b->next;
	}
}

void	set_target_node(t_stack *a, t_stack *b)
{
	t_stack	*target_node;
	t_stack	*tmp_a;
	long	max_min;

	while (b)
	{
		tmp_a = a;
		max_min = LONG_MAX;
		while (tmp_a)
		{
			if (tmp_a->value > b->value && tmp_a->value < max_min)
			{
				max_min = tmp_a->value;
				target_node = tmp_a;
			}
			tmp_a = tmp_a->next;
		}
		if (max_min == LONG_MAX)
			b->target_node = find_smallest(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	set_above_median(t_stack *stack)
{
	int	centerline;

	if (NULL == stack)
		return ;
	centerline = (ft_list_len(stack) + 1) / 2;
	while (stack)
	{
		if (stack->index <= centerline)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
	}
}
