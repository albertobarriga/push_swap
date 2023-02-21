/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_checker2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriga <abarriga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:19:35 by abarriga          #+#    #+#             */
/*   Updated: 2023/02/21 16:43:50 by abarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_push_check(t_stack **stack_out, t_stack **stack_in)
{
	t_stack	*temp;

	if (*stack_out == NULL)
		return (0);
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
		return (1);
	}
	return (0);
}

int	ft_rev_rot_check(t_stack	**stack)
{
	t_stack	*temp;
	t_stack	*penult;

	if (*stack == NULL)
		return (0);
	if (*stack && (*stack)->next)
	{
		temp = ft_last_stack(*stack);
		penult = ft_penultimate_stack(*stack);
		temp->next = *stack;
		(*stack) = temp;
		penult->next = NULL;
	}
	return (1);
}
