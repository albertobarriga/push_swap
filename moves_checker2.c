/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_checker2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriga <abarriga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:19:35 by abarriga          #+#    #+#             */
/*   Updated: 2023/02/22 16:39:42 by abarriga         ###   ########.fr       */
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

int	ft_convert(t_stack **stack_a, t_stack **stack_b, char *inst, t_list *h)
{
	if (ft_strncmp(inst, "sa\n", 5) == 0)
		return (ft_s_check(stack_a));
	else if (ft_strncmp(inst, "sb\n", 5) == 0)
		return (ft_s_check(stack_b));
	else if (ft_strncmp(inst, "ss\n", 5) == 0)
		return (ft_ss_check(stack_a, stack_b));
	else if (ft_strncmp(inst, "pa\n", 5) == 0)
		return (ft_push_check(stack_b, stack_a));
	else if (ft_strncmp(inst, "pb\n", 5) == 0)
		return (ft_push_check(stack_a, stack_b));
	else if (ft_strncmp(inst, "ra\n", 5) == 0)
		return (ft_r_check(stack_a));
	else if (ft_strncmp(inst, "rb\n", 5) == 0)
		return (ft_r_check(stack_b));
	else if (ft_strncmp(inst, "rr\n", 5) == 0)
		return (ft_rr_check(stack_a, stack_b), 1);
	else if (ft_strncmp(inst, "rra\n", 5) == 0)
		return (ft_rev_rot_check(stack_a));
	else if (ft_strncmp(inst, "rrb\n", 5) == 0)
		return (ft_rev_rot_check(stack_b));
	else if (ft_strncmp(inst, "rrr\n", 5) == 0)
		return (ft_rev_rr_check(stack_a, stack_b));
	else
		return (ft_error_check(*stack_a, *stack_b, h));
}
