/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 22:49:47 by fborroto          #+#    #+#             */
/*   Updated: 2023/09/03 23:55:35 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node, bool reverse)
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

static t_stack	*return_cheapest(t_stack *stack)
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

static void	set_cheapest(t_stack *b)
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

static void	set_price(t_stack *a, t_stack *b)
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

static void	set_target_node(t_stack *a, t_stack *b)
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

static void	set_above_median(t_stack *stack)
{
	int	i;
	int	centerline;

	i = 0;
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

void	update_struct(t_stack **a, t_stack **b)
{
	set_above_median((*a));
	set_above_median((*b));
	set_target_node((*a), (*b));
	set_price((*a), (*b));
	set_cheapest((*b));
}

static void	sort_b(t_stack **a, t_stack **b)
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
	int i = 1;
	t_stack *tmp;

	if (ft_list_len((*a)) + 1 == 5)
	{
		while (ft_list_len((*a)) > 3)
		{
			update_struct(a, b);
			finish_rotation(a, find_smallest((*a)), true);
			push_n(a, b, 2);
		}
	}
	while (ft_list_len((*a)) != 2)
	{
		push_n(a, b, 2);
	}
	ft_sort3(a);
	while ((*b))
	{
		update_struct(a, b);
		sort_b(a, b);
	}
	if (find_smallest((*a))->above_median)
	{
		while ((*a) != find_smallest((*a)))
		{
			rotate_n(a, 1);
		}
	}
	else
	{
		while ((*a) != find_smallest((*a)))
		{
			rotate_rotate_n(a, 1);
		}
	}
}
