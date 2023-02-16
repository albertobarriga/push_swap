/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriga <abarriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:33:43 by abarriga          #+#    #+#             */
/*   Updated: 2023/02/16 17:57:19 by abarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_target(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*stacka;
	int		temp_pos;
	int		temp_ind;

	while (stack_b)
	{
		stacka = stack_a;
		temp_ind = 0;
		while (stacka)
		{
			if (stacka->index > stack_b->index && (stacka->index < temp_ind || temp_ind == 0))
			{
				temp_pos = stacka->pos_r;
				temp_ind = stacka->index;
			}
			stacka = stacka->next;
		}
		if (temp_ind == 0)
		{
			stacka = stack_a;
			while (stacka)
			{
				if (stacka->index < stack_b->index && (temp_ind > stacka->index || temp_ind == 0))
				{
					temp_pos = stacka->pos_r;
					temp_ind = stacka->index;
				}
			stacka = stacka->next;
			}
		}
		stack_b->targ_pos = temp_pos;
		stack_b = stack_b->next;
	}
}

void	ft_recalculate_pos(t_stack	*stack_a, t_stack	*stack_b)
{
	// (void)stack_a;
	// (void)stack_b;

	printf("recalculate\n");
	ft_target(stack_a, stack_b);
	ft_init_pos_r(stack_a);
	ft_init_pos_r(stack_b);
	ft_cost(stack_a, stack_b);
	ft_cost_abs(stack_b);
}