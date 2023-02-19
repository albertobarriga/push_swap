/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriga <abarriga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:04:30 by abarriga          #+#    #+#             */
/*   Updated: 2023/02/19 22:41:46 by abarriga         ###   ########.fr       */
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
	ft_check_arg(argv, argc, &info, &stack_a);
	if (argc > 2)
	{
		while (i > 1)
			ft_init_stacks(&stack_a, ft_atol(argv[i-- - 1],
					2, &stack_a, &info));
	}
	else if (argc == 2)
		ft_stack_string(argv, &stack_a, &info);
	ft_push_swap(stack_a, stack_b);
	// system("leaks push_swap");
}

void	ft_push_swap(t_stack *stack_a, t_stack *stack_b)
{
	if (ft_stacksize(stack_a) == 2)
	{
		ft_order_2(stack_a);
		return ;
	}
	ft_init_order(stack_a);
	ft_push_less3(&stack_a, &stack_b);
	ft_recalculate_pos(stack_a, stack_b);
	ft_order_3(&stack_a);
	ft_recalculate_pos(stack_a, stack_b);
	ft_target(stack_a, stack_b);
	ft_recalculate_pos(stack_a, stack_b);
	ft_order(&stack_a, &stack_b);
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

/* void	print_list(t_stack *first)
{
	ft_printf("entra\n");
	while (first)
	{
		ft_printf("imprime  %i  ->pos_r= %i  ->index= %i   ->target= %i   ->costa= %i   ->costb= %i  ->costabs= %i\n", first->value, first->pos_r, first->index, first->targ_pos, first->costa, first->costb, first->cost_abs);
		first = first->next;
	}
	// ft_printf("imprime  %i  ->pos_r= %i  ->index= %i\n", first->value, first->last_pos, first->index);
	// ft_printf("imprime  %i\n", first->value);
} */

void	ft_print_list_both_stacks_data(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("STACK INFORMATION:\n");
	while (stack_a != NULL || stack_b != NULL)
	{
		if (stack_a)
		{
			ft_printf("Value: %d; Pos: %d , Final index:%d		|",
				stack_a->value, stack_a->pos_r, stack_a->index);
			stack_a = stack_a->next;
		}
		else
			ft_printf("                                   		|");
		if (stack_b)
		{
			// ft_printf("Value: %d; Pos: %d , Final index:%d, Target:%d", stack_b->value, stack_b->pos_r, stack_b->index, stack_b->targ_pos);
			ft_printf("imprime  %i  ->pos_r= %i  ->index= %i   ->target= %i   ->costa= %i   ->costb= %i  ->costabs= %i", stack_b->value, stack_b->pos_r, stack_b->index, stack_b->targ_pos, stack_b->costa, stack_b->costb, stack_b->cost_abs);
			stack_b = stack_b->next;
		}
		ft_printf("\n");
	}
}

void	ft_stack_string(char **argv, t_stack **stack_a, t_arg *info)
{
	(void)argv;
	info->max_size = ft_count_arg(info) - 1;
	info->i = info->max_size;
	while (info->i >= 0)
	{
		ft_init_stacks(stack_a, ft_atol(info->split_values[info->i], 1, stack_a, info));
		info->i--;
	}
	//liberar el doble puntero
}

int	ft_count_arg(t_arg	*info)
{
	int		i;

	i = 0;
	while (info->split_values[i])
		i++;
	return (i);
}
