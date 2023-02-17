/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriga <abarriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:47:19 by abarriga          #+#    #+#             */
/*   Updated: 2023/02/17 13:05:05 by abarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_order_3(t_stack	**stack_a)
{
	if ((*stack_a)->index > (*stack_a)->next->index && (*stack_a)->next->index > (*stack_a)->next->next->index)
	{
		ft_r(stack_a, 1);
		ft_s(stack_a, 1);
	}
	else if ((*stack_a)->index > (*stack_a)->next->index && (*stack_a)->next->index < (*stack_a)->next->next->index && (*stack_a)->index > (*stack_a)->next->next->index)
		ft_r(stack_a, 1);
	else if ((*stack_a)->index < (*stack_a)->next->index && (*stack_a)->next->index > (*stack_a)->next->next->index && (*stack_a)->index > (*stack_a)->next->next->index)
		ft_rev_rot(stack_a, 1);
	else if ((*stack_a)->index > (*stack_a)->next->index && (*stack_a)->next->index < (*stack_a)->next->next->index && (*stack_a)->index < (*stack_a)->next->next->index)
		ft_s(stack_a, 1);
	else if ((*stack_a)->index < (*stack_a)->next->index && (*stack_a)->next->index > (*stack_a)->next->next->index && (*stack_a)->index < (*stack_a)->next->next->index)
	{
		ft_rev_rot(stack_a, 1);
		ft_s(stack_a, 1);
	}
}

static int	half(t_stack	**stack_a, int len)
{
	t_stack	*temp;
	int		half;

	temp = (*stack_a);
	half = 0;
	while (temp)
	{
		half = half + temp->index;
		temp = temp->next;
	}
	half = half / len;
	return (half);
}

void	ft_push_less3(t_stack	**stack_a, t_stack	**stack_b)
{
	t_stack	*temp;
	int		len;
	int		mid;

	len = ft_stacksize(*stack_a);
	mid = half(stack_a, len);
	// printf("mid = %i\n", mid);
	temp = (*stack_a);
	while (temp && (mid > 0) && ft_stacksize(*stack_a) > 3)
	{
		if ((*stack_a)->index <= mid)
		{
			ft_push(stack_a, stack_b, 2);
			temp = (*stack_a);
		}
		else if ((*stack_a)->index > mid)
		{
			ft_r(stack_a, 1);
			mid--;
		}
	}
	temp = (*stack_a);
	len = ft_stacksize(*stack_a);
	while (len-- > 3)
		ft_push(stack_a, stack_b, 2);
	ft_recalculate_pos(*stack_a, *stack_b);
}