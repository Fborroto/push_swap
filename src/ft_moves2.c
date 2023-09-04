/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 11:02:56 by fborroto          #+#    #+#             */
/*   Updated: 2023/09/04 14:37:41 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_rotate(t_stack **a, t_stack **b)
{
	rotate_n(a, 3);
	rotate_n(b, 3);
	ft_putstr("rr\n");
}

void	rotate_rotate_n(t_stack **stack, int ab)
{
	t_stack	*tmp;

	tmp = (*stack);
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->prev->next = NULL;
	increase_index(stack);
	tmp->index = 0;
	tmp->prev = NULL;
	tmp->next = (*stack);
	(*stack)->prev = tmp;
	(*stack) = tmp;
	if (ab == 1)
		ft_putstr("rra\n");
	else if (ab == 2)
		ft_putstr("rrb\n");
	return ;
}

void	rotate_rotate_rotate(t_stack **a, t_stack **b)
{
	rotate_rotate_n(a, 3);
	rotate_rotate_n(b, 3);
	ft_putstr("rrr\n");
}
