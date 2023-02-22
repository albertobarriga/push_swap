/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriga <abarriga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:04:30 by abarriga          #+#    #+#             */
/*   Updated: 2023/02/22 20:40:37 by abarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_arg		info;
	int			i;

	stack_a = NULL;
	stack_b = NULL;
	i = argc;
	if (argc < 2)
		exit(0);
	ft_check_arg(argv, argc, &info, &stack_a);
	if (argc > 2)
	{
		while (i > 1)
			ft_init_stacks(&stack_a, ft_atol(argv[i-- - 1],
					2, &stack_a, &info));
	}
	else if (argc == 2)
		ft_stack_string(argv, &stack_a, &info);
	ft_push_swap(&stack_a, &stack_b);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
}

void	ft_push_swap(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_stacksize(*stack_a) == 2)
	{
		ft_order_2(*stack_a);
		return ;
	}
	ft_init_order(*stack_a);
	ft_push_less3(stack_a, stack_b);
	ft_recalculate_pos(*stack_a, *stack_b);
	ft_order_3(stack_a);
	ft_recalculate_pos(*stack_a, *stack_b);
	ft_target(*stack_a, *stack_b);
	ft_recalculate_pos(*stack_a, *stack_b);
	ft_order(stack_a, stack_b);
}

t_stack	*ft_init_stacks(t_stack **first, int value)
{
	t_stack	*new_node;

	new_node = (t_stack *)(malloc(sizeof(t_stack) * 2));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = *first;
	*first = new_node;
	return (*first);
}

void	ft_stack_string(char **argv, t_stack **stack_a, t_arg *info)
{
	(void)argv;
	info->max_size = ft_count_arg(info) - 1;
	info->i = info->max_size;
	while (info->i >= 0)
	{
		ft_init_stacks(stack_a, ft_atol(info->split_values[info->i],
				1, stack_a, info));
		info->i--;
	}
	ft_free_mem(info->split_values);
}
