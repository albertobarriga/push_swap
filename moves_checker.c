/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriga <abarriga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:50:30 by abarriga          #+#    #+#             */
/*   Updated: 2023/02/20 15:50:55 by abarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ss_check(t_stack **stack_a, t_stack **stack_b)
{
	ft_s(stack_a, 0);
	ft_s(stack_b, 0);
	ft_printf("ss\n");
}

void	ft_rr_check(t_stack **stack_a, t_stack **stack_b)
{
	ft_r(stack_a, 0);
	ft_r(stack_b, 0);
}

void	ft_rev_rr_check(t_stack **stack_a, t_stack **stack_b)
{
	ft_rev_rot(stack_a, 0);
	ft_rev_rot(stack_b, 0);
}
