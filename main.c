/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 23:54:23 by fborroto          #+#    #+#             */
/*   Updated: 2023/07/27 00:34:04 by fborroto         ###   ########.fr       */
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
	ft_putstr(str);
	exit(0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	if (str[i] == '-')
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
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = ft_atoi(argv[i]);
		if (j < -2147483648 || j > 2147483647)
			ft_error("Error: Invalid input\n");
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc < 4)
		return (0);
	ft_check_arg(argv);
	return (0);
}
