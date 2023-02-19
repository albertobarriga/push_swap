/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriga <abarriga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:33:50 by abarriga          #+#    #+#             */
/*   Updated: 2023/02/19 23:01:43 by abarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
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
	ft_checker(stack_a, stack_b);
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
}

void ft_convert(t_stack *stack_a, t_stack *stack_b, char *inst)
{
	if (ft_strncmp(inst, "sa\n", 5))
}