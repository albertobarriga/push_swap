/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriga <abarriga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:33:50 by abarriga          #+#    #+#             */
/*   Updated: 2023/02/20 17:27:31 by abarriga         ###   ########.fr       */
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
	//ft_printf("ESTA EN EL CHECKEER");
	ft_check_arg(argv, argc, &info, &stack_a);
	if (argc > 2)
	{
		while (i > 1)
			ft_init_stacks(&stack_a, ft_atol(argv[i-- - 1],
					2, &stack_a, &info));
	}
	else if (argc == 2)
		ft_stack_string(argv, &stack_a, &info);
	ft_checker(stack_a, stack_b);
	return (0);
}

void	ft_checker(t_stack *stack_a, t_stack *stack_b)
{
	char	*inst;

	inst = get_next_line(0);
	while (inst != NULL)
	{
		ft_convert(stack_a, stack_b, inst);
		inst = get_next_line(0);
	}
	ft_check_order(stack_a, stack_b);
}

void	ft_convert(t_stack *stack_a, t_stack *stack_b, char *inst)
{
	if (ft_strncmp(inst, "sa\n", 5))
		ft_s(&stack_a, 0);
	if (ft_strncmp(inst, "sb\n", 5))
		ft_s(&stack_b, 0);
	if (ft_strncmp(inst, "ss\n", 5))
		ft_ss_check(&stack_a, &stack_b);
	if (ft_strncmp(inst, "pa\n", 5))
		ft_push(&stack_b, &stack_a, 0);
	if (ft_strncmp(inst, "pb\n", 5))
		ft_push(&stack_a, &stack_b, 0);
	if (ft_strncmp(inst, "ra\n", 5))
		ft_r(&stack_a, 0);
	if (ft_strncmp(inst, "rb\n", 5))
		ft_r(&stack_b, 0);
	if (ft_strncmp(inst, "rr\n", 5))
		ft_rr_check(&stack_a, &stack_b);
	if (ft_strncmp(inst, "rra\n", 5))
		ft_rr(&stack_a, 0);
	if (ft_strncmp(inst, "rrb\n", 5))
		ft_rr(&stack_b, 0);
	if (ft_strncmp(inst, "rrr\n", 5))
		ft_rev_rr_check(&stack_a, &stack_b);
}

void	ft_check_order(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b == NULL)
	{
		while (stack_a && stack_a->next)
		{
			if (stack_a->value > stack_a->next->value)
			{
				ft_printf("KO\n");
				//exit (1);
			}
			stack_a = stack_a->next;
		}
		ft_printf("OK\n");
	}
	else
		ft_printf("KO\n");
}
