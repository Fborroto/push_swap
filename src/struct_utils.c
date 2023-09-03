/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:11:02 by fborroto          #+#    #+#             */
/*   Updated: 2023/09/04 00:08:06 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add(t_stack **head_ref, int value)
{
	t_stack	*new_node;
	t_stack	*last;

	new_node = NULL;
	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->value = value;
	if (*head_ref == NULL)
	{
		new_node->next = NULL;
		new_node->index = 0;
		*head_ref = new_node;
		return ;
	}
	last = (*head_ref);
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = new_node;
	new_node->prev = last;
	new_node->next = NULL;
	new_node->index = last->index + 1;
}

void	ft_init(t_stack **a, t_stack **b, char **argv, int argc)
{
	int	i;

	i = 1;
	(*a) = NULL;
	while (i < argc)
	{
		ft_add(a, ft_atoi(argv[i]));
		i++;
	}
}

t_stack	*find_smallest(t_stack *a)
{
	t_stack *smallest;

	smallest = a;

	while (a)
	{
		if (a->value < smallest->value)
			smallest = a;
		a = a->next;
	}
	return (smallest);
}