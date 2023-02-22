/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriga <abarriga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 20:38:07 by abarriga          #+#    #+#             */
/*   Updated: 2023/02/22 11:06:53 by abarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Stack out es de donde quita el nodo y el in es donde se mete el nodo
no imprime pb o pa*/
void	ft_push(t_stack **stack_out, t_stack **stack_in, int ab)
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
		if (ab == 1)
			ft_printf("pa\n");
		else if (ab == 2)
			ft_printf("pb\n");
	}
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_r(stack_a, 0);
	ft_r(stack_b, 0);
	ft_printf("rr\n");
}

void	ft_rev_rot(t_stack	**stack, int ab)
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
	if (ab == 1)
		ft_printf("rra\n");
	else if (ab == 2)
		ft_printf("rrb\n");
}

void	ft_rev_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rev_rot(stack_a, 0);
	ft_rev_rot(stack_b, 0);
	ft_printf("rrr\n");
}
