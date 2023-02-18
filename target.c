/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alberto <alberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:33:43 by abarriga          #+#    #+#             */
/*   Updated: 2023/02/18 20:36:49 by alberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_list_both_stacks_data(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("STACK INFORMATION:\n");
	while (stack_a != NULL || stack_b != NULL)
	{
		if (stack_a)
		{
			ft_printf("Value: %d; Pos: %d , Final index:%d		|",
				stack_a->value, stack_a->pos_r, stack_a->index);
			stack_a = stack_a->next;
		}
		else
			ft_printf("                                   		|");
		if (stack_b)
		{
			// ft_printf("Value: %d; Pos: %d , Final index:%d, Target:%d", stack_b->value, stack_b->pos_r, stack_b->index, stack_b->targ_pos);
			ft_printf("imprime  %i  ->pos_r= %i  ->index= %i   ->target= %i   ->costa= %i   ->costb= %i  ->costabs= %i", stack_b->value, stack_b->pos_r, stack_b->index, stack_b->targ_pos, stack_b->costa, stack_b->costb, stack_b->cost_abs);
			stack_b = stack_b->next;
		}
		ft_printf("\n");
	}
}

void	ft_target(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*stacka;
	int		temp_pos;
	int		temp_ind;

	while (stack_b)
	{
		stacka = stack_a;
		temp_ind = 0;
		temp_pos = 0;
		while (stacka)
		{
			if (stacka->index > stack_b->index
				&& (stacka->index < temp_ind || temp_ind == 0))
			{
				temp_pos = stacka->pos_r;
				temp_ind = stacka->index;
			}
			stacka = stacka->next;
		}
		if (temp_ind == 0)
			temp_pos = ft_target_back(stack_a, stack_b);
		stack_b->targ_pos = temp_pos;
		stack_b = stack_b->next;
	}
}

int	ft_target_back(t_stack *stack_a, t_stack *stack_b)
{
	int	temp_pos;
	int	temp_ind;

	temp_pos = 0;
	temp_ind = 0;
	while (stack_a)
	{
		if (stack_a->index < stack_b->index
			&& (temp_ind > stack_a->index || temp_ind == 0))
		{
			temp_pos = stack_a->pos_r;
			temp_ind = stack_a->index;
		}
	stack_a = stack_a->next;
	}
	return (temp_pos);
}

void	ft_recalculate_pos(t_stack	*stack_a, t_stack	*stack_b)
{
	ft_target(stack_a, stack_b);
	ft_init_pos_r(stack_a);
	ft_init_pos_r(stack_b);
	ft_cost(stack_a, stack_b);
	ft_cost_abs(stack_b);
}
