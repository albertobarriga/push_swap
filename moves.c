/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alberto <alberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:24:54 by abarriga          #+#    #+#             */
/*   Updated: 2023/02/18 20:40:59 by alberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_s(t_stack **stack, int ab)
{
	t_stack	*temp;

	temp = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	temp->next = (*stack);
	(*stack) = temp;
	if (ab == 1)
		ft_printf("sa\n");
	else if (ab == 2)
		ft_printf("sb\n");
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_s(stack_a, 0);
	ft_s(stack_b, 0);
	ft_printf("ss\n");
}

// Rota el primer nodo y lo pone al final
void	ft_r(t_stack	**stack, int ab)
{
	t_stack	*temp;
	t_stack	*last;

	if ((*stack) && (*stack)->next)
	{
		temp = (*stack)->next;
		last = ft_last_stack(*stack);
		last->next = (*stack);
		last = last->next;
		last->next = NULL;
		*stack = temp;
		if (ab == 1)
			ft_printf("ra\n");
		else if (ab == 2)
			ft_printf("rb\n");
	}
}

t_stack	*ft_last_stack(t_stack	*stack)
{
	while (stack->next)
	{
		stack = stack->next;
	}
	return (stack);
}

t_stack	*ft_penultimate_stack(t_stack	*stack)
{
	t_stack	*temp;

	while (stack->next)
	{
		temp = stack;
		stack = stack->next;
	}
	return (temp);
}
