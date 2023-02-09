/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriga <abarriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:24:54 by abarriga          #+#    #+#             */
/*   Updated: 2023/02/09 17:42:31 by abarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_stack **stack_a)
{
	t_stack	*temp;

	temp = (*stack_a)->next;
	(*stack_a)->next = (*stack_a)->next->next;
	temp->next = (*stack_a);
	(*stack_a) = temp;
	ft_printf("sa\n");
}

void	ft_swap_b(t_stack **stack_b)
{
	t_stack	*temp;

	temp = (*stack_b)->next;
	(*stack_b)->next = (*stack_b)->next->next;
	temp->next = (*stack_b);
	(*stack_b) = temp;
	ft_printf("sb\n");
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap_a(stack_a);
	(void)stack_b;
	// ft_swap_b(stack_b);
}

void	ft_push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (stack_a)
	{
		if (stack_b)
		{
			temp = *stack_a;
			(*stack_a) = (*stack_a)->next;
			(*stack_b) = temp;
			(*stack_b)->next = NULL;
		}
		ft_printf("pb\n");
	}
}

void	ft_push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (stack_b)
	{
			temp = *stack_b;
			(*stack_b) = (*stack_b)->next;
			(*stack_a) = temp;
			(*stack_a)->next = NULL;
		ft_printf("pa\n");
	}
}