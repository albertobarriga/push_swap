/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriga <abarriga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:42:35 by abarriga          #+#    #+#             */
/*   Updated: 2023/02/22 11:09:13 by abarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_cost(t_stack *stack_a, t_stack *stack_b)
{
	int	len_a;
	int	len_b;

	len_a = ft_stacksize(stack_a);
	len_b = ft_stacksize(stack_b);
	while (stack_b)
	{
		if (stack_b->pos_r <= (len_b / 2))
			stack_b->costb = stack_b->pos_r;
		else if (stack_b->pos_r > (len_b / 2))
			stack_b->costb = (len_b - stack_b->pos_r) * -1;
		if (stack_b->targ_pos <= (len_a / 2))
			stack_b->costa = stack_b->targ_pos;
		else if (stack_b->targ_pos > (len_a / 2))
			stack_b->costa = (len_a - stack_b->targ_pos) * -1;
		stack_b = stack_b->next;
	}
}

void	ft_cost_abs(t_stack	*stack_b)
{
	while (stack_b)
	{
		if (stack_b->costa >= 0 && stack_b->costb >= 0)
		{
			if (stack_b->costa >= stack_b->costb)
				stack_b->cost_abs = stack_b->costa;
			else
				stack_b->cost_abs = stack_b->costb;
		}
		else if (stack_b->costa < 0 && stack_b->costb < 0)
		{
			if (stack_b->costa < stack_b->costb)
				stack_b->cost_abs = stack_b->costa * -1;
			else
				stack_b->cost_abs = stack_b->costb * -1;
		}
		else
		{
			if (stack_b->costa < 0)
				stack_b->cost_abs = (-1 * stack_b->costa) + stack_b->costb;
			else if (stack_b->costb < 0)
				stack_b->cost_abs = (-1 * stack_b->costb) + stack_b->costa;
		}
		stack_b = stack_b->next;
	}
}

int	ft_stacksize(t_stack *lst)
{
	int	count;

	count = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
