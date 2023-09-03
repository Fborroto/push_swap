/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fborroto <fborroto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 23:55:03 by fborroto          #+#    #+#             */
/*   Updated: 2023/09/03 23:49:20 by fborroto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stdbool.h"
# include "stdio.h"
# include "stdlib.h"
# include "unistd.h"
# include "limits.h"

typedef struct s_stack
{
	int				value;
	int				index;
	int				final_index;
	int				price;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

void				finish_rotation(t_stack **stack, t_stack *top_node, bool a);
void				update_struct(t_stack **a, t_stack **b);
void				ft_rotate_rotate(t_stack **a, t_stack **b);
t_stack				*find_smallest(t_stack *a);
void				ft_sort3(t_stack **a);
int					ft_list_len(t_stack *stack);
void				ft_big_sort(t_stack **a, t_stack **b);
void				printstack(t_stack **stack);
void				ft_add(t_stack **head_ref, int value);
void				swap_n(t_stack **stack, int ab);
void				decrease_index(t_stack **stack);
void				increase_index(t_stack **stack);
void				rotate_rotate_n(t_stack **stack, int ab);
void				rotate_rotate_rotate(t_stack **a, t_stack **b);
void				rotate_n(t_stack **stack, int ab);
void				ft_init(t_stack **a, t_stack **b, char **argv, int argc);
void				push_n(t_stack **from, t_stack **to, int ab);
long				ft_atoi(const char *str);
void				ft_putstr(char *str);
void				ft_error(char *str);
long				ft_atoi(const char *str);
void				ft_check_arg(char **argv);
void				ft_check_double(t_stack *a);
t_stack				*last_node(t_stack **stack);
#endif