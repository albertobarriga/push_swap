/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriga <abarriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:24:54 by abarriga          #+#    #+#             */
/*   Updated: 2023/02/13 17:16:29 by abarriga         ###   ########.fr       */
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
	ft_swap_a(stack_b);
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

// Rota el primer nodo y lo pone al final
void	ft_r(t_stack	**stack)
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
	}
}

t_stack	*ft_last_stack(t_stack	*stack)
{
	while(stack->next)
	{
		stack = stack->next;
	}
	return (stack);
}

t_stack	*ft_penultimate_stack(t_stack	*stack)
{
	t_stack	*temp;
	
	while(stack->next)
	{
		temp = stack;
		stack = stack->next;
	}
	return (temp);
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_r(stack_a);
	ft_r(stack_b);
	
}

void	ft_rev_rot(t_stack	**stack)
{
	t_stack	*temp;
	t_stack	*penult;
	
	if (*stack && (*stack)->next)
	{
		temp = ft_last_stack(*stack);
		penult = ft_penultimate_stack(*stack);
		temp->next = *stack;
		(*stack) = temp;
		penult->next = NULL;
	}
}

void	ft_rev_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rev_rot(stack_a);
	ft_rev_rot(stack_b);
}