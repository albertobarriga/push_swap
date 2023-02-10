/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alberto <alberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:24:54 by abarriga          #+#    #+#             */
/*   Updated: 2023/02/10 02:27:35 by alberto          ###   ########.fr       */
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

/* Stack out es de donde quita el nodo y el in es donde se mete el nodo
no imprime pb o pa*/
void	ft_push_b(t_stack **stack_out, t_stack **stack_in)
{
	t_stack	*temp;

	if (*stack_out)
	{
		if (*stack_in)
		{
			temp = *stack_out;
			(*stack_out) = (*stack_out)->next;
			temp->next = *stack_in;
			(*stack_in) = temp;
		}
		else
		{
			temp = *stack_out;
			(*stack_out) = (*stack_out)->next;
			(*stack_in) = temp;
			(*stack_in)->next = NULL;
		}
	}
}

void	ft_r(t_stack	**stack)
{
	t_stack	*temp;
	t_stack	*last;

	temp = (*stack)->next;
	last = ft_last_stack(*stack);
	last->next = (*stack);
	last = last->next;
	last->next = NULL;
	*stack = temp;
}

t_stack	*ft_last_stack(t_stack	*stack)
{
	while(stack->next)
	{
		stack = stack->next;
	}
	return (stack);
}
// HACE FALTA ARREGLAR NO FUNCIONA

/* void	ft_push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (*stack_b)
	{
			temp = *stack_b;
			(*stack_b) = (*stack_b)->next;
			(*stack_a) = temp;
			(*stack_a)->next = NULL;
		ft_printf("pa\n");
	}
} */