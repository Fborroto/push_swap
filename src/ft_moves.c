/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 09:50:54 by fborroto          #+#    #+#             */
/*   Updated: 2023/09/04 14:41:24 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_n(t_stack **stack, int ab)
{
	int	tmp;

	if (!((*stack) && (*stack)->next))
		return ;
	tmp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = tmp;
	if (ab == 1)
		ft_putstr("sa\n");
	else if (ab == 2)
		ft_putstr("sb\n");
	return ;
}

void	ft_swap_swap(t_stack **a, t_stack **b)
{
	swap_n(a, 3);
	swap_n(b, 3);
	ft_putstr("ss\n");
}

void	push_finish(t_stack **from, t_stack **to, t_stack *tmp, int ab)
{
	tmp->next = (*to);
	(*to)->prev = tmp;
	(*to) = tmp;
	decrease_index(from);
	if (ab == 1)
		ft_putstr("pa\n");
	else if (ab == 2)
		ft_putstr("pb\n");
}

void	push_n(t_stack **from, t_stack **to, int ab)
{
	t_stack	*tmp;

	if (!(*from))
		return ;
	tmp = (*from);
	if ((*from)->next)
	{
		(*from) = (*from)->next;
		(*from)->prev = NULL;
	}
	else
		(*from) = NULL;
	increase_index(to);
	if ((*to) == NULL)
	{
		(*to) = tmp;
		tmp->next = NULL;
		decrease_index(from);
		ft_putstr("pb\n");
		return ;
	}
	push_finish(from, to, tmp, ab);
}

void	rotate_n(t_stack **stack, int ab)
{
	t_stack	*tmp;

	if (!(*stack))
		return ;
	tmp = (*stack);
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	(*stack)->index = tmp->index + 1;
	tmp->next = (*stack);
	(*stack)->prev = tmp;
	(*stack) = (*stack)->next;
	tmp->next->next = NULL;
	(*stack)->prev = NULL;
	decrease_index(stack);
	if (ab == 1)
		ft_putstr("ra\n");
	else if (ab == 2)
		ft_putstr("rb\n");
}
