/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriga <abarriga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:50:30 by abarriga          #+#    #+#             */
/*   Updated: 2023/02/21 16:43:00 by abarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ss_check(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_s_check(stack_a) == 0)
		return (0);
	if (ft_s_check(stack_b) == 0)
		return (0);
	return (1);
}

int	ft_rr_check(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_r_check(stack_a) == 0)
		return (0);
	if (ft_r_check(stack_b) == 0)
		return (0);
	return (1);
}

int	ft_rev_rr_check(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_rev_rot_check(stack_a) == 0)
		return (0);
	if (ft_rev_rot_check(stack_b) == 0)
		return (0);
	return (1);
}

int	ft_s_check(t_stack **stack)
{
	t_stack	*temp;

	if (*stack == NULL)
		return (0);
	temp = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	temp->next = (*stack);
	(*stack) = temp;
	return (1);
}

int	ft_r_check(t_stack	**stack)
{
	t_stack	*temp;
	t_stack	*last;

	if (*stack == NULL)
		return (0);
	if ((*stack) && (*stack)->next)
	{
		temp = (*stack)->next;
		last = ft_last_stack(*stack);
		last->next = (*stack);
		last = last->next;
		last->next = NULL;
		*stack = temp;
		return (1);
	}
	return (0);
}
