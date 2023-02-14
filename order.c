/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriga <abarriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:47:19 by abarriga          #+#    #+#             */
/*   Updated: 2023/02/14 19:22:57 by abarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_order_3(t_stack	**stack_a)
{
	if ((*stack_a)->index > (*stack_a)->next->index && (*stack_a)->next->index > (*stack_a)->next->next->index)
	{
		ft_r(stack_a);
		ft_s(stack_a);
	}
	else if ((*stack_a)->index > (*stack_a)->next->index && (*stack_a)->next->index < (*stack_a)->next->next->index && (*stack_a)->index > (*stack_a)->next->next->index)
		ft_r(stack_a);
	else if ((*stack_a)->index < (*stack_a)->next->index && (*stack_a)->next->index > (*stack_a)->next->next->index && (*stack_a)->index > (*stack_a)->next->next->index)
		ft_rev_rot(stack_a);
	else if ((*stack_a)->index > (*stack_a)->next->index && (*stack_a)->next->index < (*stack_a)->next->next->index && (*stack_a)->index < (*stack_a)->next->next->index)
		ft_s(stack_a);
	else if ((*stack_a)->index < (*stack_a)->next->index && (*stack_a)->next->index > (*stack_a)->next->next->index && (*stack_a)->index < (*stack_a)->next->next->index)
	{
		ft_rev_rot(stack_a);
		ft_s(stack_a);
	}
}