/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orderall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriga <abarriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:40:26 by abarriga          #+#    #+#             */
/*   Updated: 2023/02/17 16:38:19 by abarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_less_cost(t_stack	**stack_b)
{
	t_stack	*stack;
	int	cost;

	cost = INT_MAX;
	stack = *stack_b;
	while (stack)
	{
		if (cost > stack->cost_abs)
			cost = stack->cost_abs;
		stack = stack->next;
	}
	return (cost);
}

void ft_algorithm(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*stack;
	int cost_less;
	int movesb;
	int	movesa;

	// printf("entra en la funcion de ordeancion\n");
	stack = (*stack_b);
	cost_less = ft_less_cost(stack_b);
	while (stack && stack->cost_abs != cost_less)
		stack = stack->next;
	movesb = stack->costb;
	movesa = stack->costa;
	while (movesb > 0 && movesa > 0)
	{
		ft_rr(stack_a, stack_b);
		movesa--;
		movesb--;
	}
	while (movesb < 0 && movesa < 0)
	{
		ft_rev_rr(stack_a, stack_b);
		movesa++;
		movesb++;
	}
	while (movesb > 0)
	{
		ft_r(stack_b, 2);
		movesb--;
	}
	while (movesb < 0)
	{
		ft_rev_rot(stack_b, 2);
		movesb++;
	}
	while (movesa > 0)
	{
		ft_r(stack_a, 1);
		movesa--;
	}
	while (movesa < 0)
	{
		ft_rev_rot(stack_a, 1);
		movesa++;
		// printf("");
	}
	if (movesa == 0 && movesb == 0)
		ft_push(stack_b, stack_a, 1);
	ft_recalculate_pos(*stack_a, *stack_b);
}

void	ft_order(t_stack **stack_a, t_stack **stack_b)
{
	while (*stack_b)
	{
		ft_algorithm(stack_a, stack_b);
		ft_recalculate_pos(*stack_a, *stack_b);
		ft_print_list_both_stacks_data(*stack_a, *stack_b);
	}
}

void	ft_lap_numbers(t_stack *stack_a, t_stack *stack_b)
{
	int len;
	t_stack	*stack;

	stack = stack_a;

	len = ft_stacksize(stack_a);
	if (stack_a->index != 1)
	{
		while (stack_a )
	}
	while (stack_a)
}