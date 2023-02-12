/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alberto <alberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:33:43 by abarriga           #+#    #+#             */
/*   Updated: 2023/02/12 19:33:44 by alberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    ft_target(t_stack *stack_a, t_stack *stack_b)
{
    t_stack stacka;
    int temp;

    while(stack_b)
    {
        stacka = stack_a;
        temp = 0;
        while (stacka)
        {
            if (stacka->index < stack_b->index && temp)
            {
                temp = stacka->pos_r;
            }
        stack = stacka->next;
        }
        if (temp == 0)
        stack_b = stack_b->next;
    }
}