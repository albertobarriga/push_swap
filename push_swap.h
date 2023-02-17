/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriga <abarriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:04:44 by abarriga          #+#    #+#             */
/*   Updated: 2023/02/17 12:35:09 by abarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "libft/libft.h"
# include "libft/printf/ft_printf.h"

typedef struct s_stack
{
	int	value;
	int	index;
	int	pos_r;
	int	targ_pos;
	int	costa;
	int	costb;
	int	cost_abs;
	struct	s_stack	*next;
}					t_stack;

typedef struct s_arg
{
	char	**split_values;
	int		max_size;
	int		i;
}				t_arg;

int	main(int argc, char **argv);

t_stack *ft_init_stacks(t_stack **first, int value);

void	print_list(t_stack *first);

void	ft_print_list_both_stacks_data(t_stack *stack_a, t_stack *stack_b);

int		ft_atol(const char *str);

void	ft_stack_string (char **argv, t_stack **stack_a, t_arg *info);

int		ft_count_arg(t_arg	*info);

void	ft_check_arg(char **argv, int argc, t_arg *info);

void	ft_check_duplicate_string(t_arg	*info);

void	ft_check_duplicate_args(char **argv);

void	ft_error_input();

void	ft_check_num(char **argv);

void	ft_check_atol(long res);

void    ft_init_order(t_stack   *node);

int		ft_stacksize(t_stack *lst);

void    ft_init_pos_r(t_stack *node);

void	ft_init_pos_ord(t_stack *node);

void    ft_target(t_stack *stack_a, t_stack *stack_b);

// FUNCIONS THAT ORDER THE STACK

void	ft_s(t_stack **stack_a, int ab);

// void	ft_swap_b(t_stack **stack_b);

void	ft_ss(t_stack **stack_a, t_stack **stack_b);

void	ft_push(t_stack **stack_out, t_stack **stack_in, int ab);

void	ft_r(t_stack	**stack, int ab);

t_stack	*ft_last_stack(t_stack	*stack);

void	ft_rr(t_stack **stack_a, t_stack **stack_b);

t_stack	*ft_penultimate_stack(t_stack	*stack);

void	ft_rev_rot(t_stack	**stack, int ab);

void	ft_rev_rr(t_stack **stack_a, t_stack **stack_b);

// Calculate costs for movements

void 	ft_cost(t_stack *stack_a, t_stack *stack_b);

void	ft_recalculate_pos(t_stack	*stack_a, t_stack	*stack_b);

void ft_cost_abs(t_stack	*stack_b);

// Algorithm to order the stacks

void	ft_order_3(t_stack	**stack_a);

void	ft_push_less3(t_stack	**stack_a, t_stack	**stack_b);

int		ft_less_cost(t_stack	**stack_b);

void	ft_order(t_stack **stack_a, t_stack **stack_b);

#endif