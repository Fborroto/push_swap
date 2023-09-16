/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 22:49:47 by fborroto          #+#    #+#             */
/*   Updated: 2023/09/04 14:36:41 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node,
		bool reverse)
{
	if (reverse)
	{
		while (*a != cheapest_node->target_node && *b != cheapest_node)
			ft_rotate_rotate(a, b);
	}
	else
	{
		while (*a != cheapest_node->target_node && *b != cheapest_node)
			rotate_rotate_rotate(a, b);
	}
}

void	finish_rotation(t_stack **stack, t_stack *top_node, bool a)
{
	while (*stack != top_node)
	{
		if (a)
		{
			if (top_node->above_median)
				rotate_n(stack, 1);
			else
				rotate_rotate_n(stack, 1);
		}
		else
		{
			if (top_node->above_median)
				rotate_n(stack, 2);
			else
				rotate_rotate_n(stack, 2);
		}
	}
}

void	update_struct(t_stack **a, t_stack **b)
{
	set_above_median((*a));
	set_above_median((*b));
	set_target_node((*a), (*b));
	set_price((*a), (*b));
	set_cheapest((*b));
}

static	void	sort_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = return_cheapest(*b);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node, true);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		rotate_both(a, b, cheapest_node, false);
	finish_rotation(b, cheapest_node, false);
	finish_rotation(a, cheapest_node->target_node, true);
	push_n(b, a, 1);
}

void	ft_big_sort(t_stack **a, t_stack **b)
{
	if (ft_list_len((*a)) + 1 == 5)
	{
		while (ft_list_len((*a)) > 2)
		{
			update_struct(a, b);
			finish_rotation(a, find_smallest((*a)), true);
			push_n(a, b, 2);
		}
	}
	while (ft_list_len((*a)) != 2)
		push_n(a, b, 2);
	ft_sort3(a);
	while ((*b))
	{
		update_struct(a, b);
		sort_b(a, b);
	}
	if (find_smallest((*a))->above_median)
		while ((*a) != find_smallest((*a)))
			rotate_n(a, 1);
	else
		while ((*a) != find_smallest((*a)))
			rotate_rotate_n(a, 1);
}
