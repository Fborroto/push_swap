/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 23:55:03 by fborroto          #+#    #+#             */
/*   Updated: 2023/08/31 16:59:26 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stdlib.h"
# include "stdio.h"
# include "unistd.h"
# include "stdbool.h"

typedef struct s_stack
{
	int				value;
	int				index;
	int				final_index;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

void	printstack(t_stack **stack);
void	ft_add(t_stack **head_ref, int value);
void	ft_init(t_stack **a, t_stack **b, char **argv, int argc);
long	ft_atoi(const char *str);
void	ft_putstr(char *str);
void	ft_error(char *str);
long	ft_atoi(const char *str);
void	ft_check_arg(char **argv);
char	**ft_split(char *s, char c);

#endif