/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:59:12 by fborroto          #+#    #+#             */
/*   Updated: 2023/09/16 18:01:10 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_close(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = (*a);
	while (tmp->next != NULL)
	{
		free(tmp);
		tmp = tmp->next;
	}
	free(tmp);
	if (!(*b))
		exit(0);
	tmp = (*b);
	while (tmp->next != NULL)
	{
		free(tmp);
		tmp = tmp->next;
	}
	free(tmp);
	exit(0);
}

int	ft_check_order(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	ft_list_len(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack->index);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 3)
		return (0);
	ft_check_arg(argv);
	ft_init(&a, argv, argc);
	ft_check_double(a);
	if (ft_check_order(a) == 1)
	{
		ft_close(&a, &b);
	}
	else
	{
		if (ft_list_len(a) + 1 == 2)
			swap_n(&a, 1);
		else if (ft_list_len(a) + 1 == 3)
			ft_sort3(&a);
		else
			ft_big_sort(&a, &b);
		ft_close(&a, &b);
	}
	return (0);
}
