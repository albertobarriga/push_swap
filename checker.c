/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriga <abarriga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:33:50 by abarriga          #+#    #+#             */
/*   Updated: 2023/02/21 17:04:50 by abarriga         ###   ########.fr       */
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
	ft_checker(&stack_a, &stack_b);
}

// void	ft_checker(t_stack *stack_a, t_stack *stack_b)
// {
// 	char	*inst;

// 	inst = get_next_line(0);
// 	while (inst != NULL)
// 	{
// 		ft_convert(stack_a, stack_b, inst);
// 		inst = get_next_line(0);
// 	}
// 	if (ft_check_order(stack_a, stack_b) == 0)
// 		ft_printf("\nOK\n");
// }

void	ft_checker(t_stack **stack_a, t_stack **stack_b)
{
	char	*inst;

	if (ft_check_order(*stack_a, *stack_b) == 1)
	{
		ft_printf("OK\n");
		exit (0);
	}
	while (1)
	{
		inst = get_next_line(0);
		if (!inst)
			break ;
		if (ft_convert(stack_a, stack_b, inst) == 0)
		{
			ft_printf("KO\n");
			exit (0);
			//free(inst);
		}
		// ft_print_list_both_stacks_data(*stack_a, *stack_b);
		//free(inst);
	}
	if (ft_check_order(*stack_a, *stack_b) == 1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	ft_convert(t_stack **stack_a, t_stack **stack_b, char *inst)
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
