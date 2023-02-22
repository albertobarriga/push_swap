/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriga <abarriga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:33:50 by abarriga          #+#    #+#             */
/*   Updated: 2023/02/22 16:41:25 by abarriga         ###   ########.fr       */
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
	if (i == 1)
		return (0);
	ft_check_arg(argv, argc, &info, &stack_a);
	if (argc > 2)
	{
		while (i > 1)
			ft_init_stacks(&stack_a, ft_atol(argv[i-- - 1],
					2, &stack_a, &info));
	}
	else if (argc == 2)
		ft_stack_string(argv, &stack_a, &info);
	ft_checker(&stack_a, &stack_b);
	system("leaks checker");
}

t_list	*ft_read_moves(t_list *inst)
{
	inst = ft_lstnew((char *)get_next_line(0));
	while (ft_lstlast(inst)->content)
		ft_lstadd_back(&inst, ft_lstnew((char *)get_next_line(0)));
	return (inst);
}

void	ft_checker(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_list	*temp;
	t_list	*inst;

	i = 0;
	inst = NULL;
	inst = ft_read_moves(inst);
	temp = inst;
	while (temp->content)
	{
		if (ft_convert(stack_a, stack_b, temp->content, inst) == 0)
		{
			ft_printf("KO\n");
			ft_lstclear(&inst, free);
			exit (0);
		}
		temp = temp->next;
		ft_lstclear(&inst, free);
	}
	if (ft_check_order(*stack_a, *stack_b) == 1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	ft_error_check(t_stack *stack_a, t_stack *stack_b, t_list *inst)
{
	ft_printf("ERROR\n");
	ft_lstclear(&inst, free);
	ft_free_stack(&stack_a);
	ft_free_stack(&stack_b);
	exit (0);
	return (0);
}

int	ft_check_order(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b == NULL)
	{
		while (stack_a && stack_a->next)
		{
			if (stack_a->value > stack_a->next->value)
				return (0);
			stack_a = stack_a->next;
		}
	}
	else
		return (0);
	return (1);
}
