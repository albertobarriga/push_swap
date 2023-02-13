/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriga <abarriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:33:43 by abarriga          #+#    #+#             */
/*   Updated: 2023/02/13 15:54:03 by abarriga         ###   ########.fr       */
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
				// printf("temp_index = %i y stack_a index = %i\n", temp_ind, stacka->index);
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
					printf("dentro del bucle%i\n", stacka->index);
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