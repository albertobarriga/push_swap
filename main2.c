/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriga <abarriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:04:30 by abarriga          #+#    #+#             */
/*   Updated: 2023/02/08 18:38:05 by abarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	//t_stack		*stack_b;
	t_arg		info;
	int			i;

	stack_a = NULL;
	//stack_b = NULL;
	i = argc;
	//ft_init_info(info);
	ft_check_arg(argv, argc, &info);
	if (argc > 2)
	{
		while (i > 1)
		{
			ft_init_stacks(&stack_a, ft_atol(argv[i - 1]));
			i--;
		}
	}
	else if (argc == 2)
	{
		ft_stack_string(argv, &stack_a, &info);
	}
	ft_init_order(stack_a);
	ft_ss(&stack_a, &stack_a);
	print_list(stack_a);
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

void	print_list(t_stack *first)
{
	while (first->next)
	{
		ft_printf("imprime  %i  ->pos_r= %i  ->index= %i\n", first->value, first->pos_r, first->index);
		first = first->next;
	}
	ft_printf("imprime  %i  ->pos_r= %i  ->index= %i\n", first->value, first->last_pos, first->index);
}

void	ft_stack_string(char **argv, t_stack **stack_a, t_arg *info)
{
	(void)argv;
	info->max_size = ft_count_arg(info) - 1;
	info->i = info->max_size;
	while (info->i >= 0)
	{
		ft_init_stacks(stack_a, ft_atol(info->split_values[info->i]));
		info->i--;
	}
}

int	ft_count_arg(t_arg	*info)
{
	int		i;

	i = 0;
	while (info->split_values[i])
		i++;
	return (i);
}
