/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 23:54:23 by fborroto          #+#    #+#             */
/*   Updated: 2023/08/30 23:21:27 by fborroto         ###   ########.fr       */
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
	printf("%s\n",str);
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
		ft_error("Error: Invalid input\n");
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			ft_error("Error: Invalid input\n");
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}

void	ft_check_arg(char **argv)
{
	int		i;
	long	j;

	i = 1;
	while (argv[i])
	{
		j = ft_atoi(argv[i]);
		if (j <= -2147483649 || j >= 2147483648)
		{
			ft_error("Error: element is not an int\n");
		}
		i++;
	}
	
}

void ft_check(char **argv)
{
	ft_check_arg(argv);

}

void ft_add(t_stack **head_ref, int argv)
{

}

void	ft_init(t_stack **a, t_stack **b, char **argv, int argc)
{
	int	i;
	
	(*b) = (t_stack *)malloc(sizeof(t_stack));
	if (!(*b))
		return ;
	
	(*a) = malloc(sizeof(t_stack *));
	i = 1;
	while (i < argc)
	{
		ft_add(a,ft_atoi(argv[i]));
		i++;
	}
	
}

// t_stack	*ft_init_stack(char **list, int len_list)
// {
// 	int			i;
// 	t_stack		*top;

// 	top = NULL;
// 	i = 1;
// 	if (len_list == 0)
// 	{
// 		top = malloc(sizeof(t_stack *));
// 		if (!top)
// 			return (NULL);
// 		top->index = -1;
// 		return (top);
// 	}
// 	while (i < len_list)
// 	{
// 		ft_append_node(&top, ft_atoi(list[i]));
// 		i++;
// 	}
// 	return (top);
// }


// void	ft_append_node(t_stack **head_ref, int new_value)
// {
// 	t_stack	*new_node;
// 	t_stack	*last;

// 	new_node = NULL;
// 	new_node = malloc(sizeof(t_stack *));
// 	if (!new_node)
// 		return ;
// 	new_node->value = new_value;
// 	new_node->next = NULL;
// 	new_node->prev = NULL;
// 	if (*head_ref == NULL)
// 	{
// 		new_node->index = 0;
// 		*head_ref = new_node;
// 		return ;
// 	}
// 	last = *head_ref;
// 	while (last->next != NULL)
// 	{
// 		last = last->next;
// 	}
// 	last->next = new_node;
// 	new_node->prev = last;
// 	new_node->index = last->index + 1;
// }

void	ft_free(t_stack **a, t_stack **b)
{
	free(a);
	free(b);
}

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	
	if (argc < 3)
		return (0);
	
	ft_check_arg(argv);
	ft_init(&a, &b, argv, argc - 1);
	printf("arriva alla fine \n");
	
	return (0);
}
