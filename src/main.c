/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:59:12 by fborroto          #+#    #+#             */
/*   Updated: 2023/08/31 16:59:15 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printstack(t_stack **stack)
{
	t_stack	*tmp;

	tmp = (*stack);
	printf("\n------print Stack------\n");
	while (tmp)
	{
		printf("| value : %i index : %i | \n", tmp->value, tmp->index);
		tmp = tmp->next;
	}
	printf("\n----------------------\n");
}

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
	tmp = (*b);
	while (tmp->next != NULL)
	{
		free(tmp);
		tmp = tmp->next;
	}
	free(tmp);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 3)
		return (0);
	ft_check_arg(argv);
	ft_init(&a, &b, argv, argc);
	ft_check_double(a);
	printstack(&a);
	printf("arriva alla fine \n");
	ft_close(&a, &b);
	return (0);
}
