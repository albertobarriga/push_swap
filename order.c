/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriga <abarriga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:47:19 by abarriga          #+#    #+#             */
/*   Updated: 2023/02/22 11:06:45 by abarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_order_3(t_stack	**stack_a)
{
	if ((*stack_a)->index > (*stack_a)->next->index
		&& (*stack_a)->next->index > (*stack_a)->next->next->index)
	{
		ft_r(stack_a, 1);
		ft_s(stack_a, 1);
	}
	else if ((*stack_a)->index > (*stack_a)->next->index
		&& (*stack_a)->next->index < (*stack_a)->next->next->index
		&& (*stack_a)->index > (*stack_a)->next->next->index)
		ft_r(stack_a, 1);
	else if ((*stack_a)->index < (*stack_a)->next->index
		&& (*stack_a)->next->index > (*stack_a)->next->next->index
		&& (*stack_a)->index > (*stack_a)->next->next->index)
		ft_rev_rot(stack_a, 1);
	else if ((*stack_a)->index > (*stack_a)->next->index
		&& (*stack_a)->next->index < (*stack_a)->next->next->index
		&& (*stack_a)->index < (*stack_a)->next->next->index)
		ft_s(stack_a, 1);
	else if ((*stack_a)->index < (*stack_a)->next->index
		&& (*stack_a)->next->index > (*stack_a)->next->next->index
		&& (*stack_a)->index < (*stack_a)->next->next->index)
	{
		ft_rev_rot(stack_a, 1);
		ft_s(stack_a, 1);
	}
}

void	ft_push_less3(t_stack	**stack_a, t_stack	**stack_b)
{
	t_stack	*temp;
	int		mid;
	int		i;

	mid = ft_stacksize(*stack_a) / 2;
	i = mid;
	temp = (*stack_a);
	while (temp && (i > 0) && ft_stacksize(*stack_a) > 3)
	{
		if ((*stack_a)->index <= mid)
		{
			ft_push(stack_a, stack_b, 2);
			temp = (*stack_a);
		}
		else if ((*stack_a)->index > mid)
		{
			ft_r(stack_a, 1);
			i--;
		}
	}
	temp = (*stack_a);
	while (ft_stacksize(*stack_a) > 3)
		ft_push(stack_a, stack_b, 2);
	ft_recalculate_pos(*stack_a, *stack_b);
}

void	ft_order_2(t_stack *stack_a)
{
	if (stack_a->value > stack_a->next->value)
	{
		ft_s(&stack_a, 1);
	}
}
