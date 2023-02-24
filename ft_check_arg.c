/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriga <abarriga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:17:11 by abarriga          #+#    #+#             */
/*   Updated: 2023/02/23 12:29:07 by abarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_arg(char **argv, int argc, t_arg *info, t_stack **stack_a)
{
	if (argc == 2)
	{
		info->split_values = ft_split(argv[1], ' ');
		info->max_size = ft_count_arg(info) - 1;
		info->i = info->max_size;
		if (info->max_size == 0)
			exit(0);
		if (ft_check_num(info->split_values) == 0
			|| ft_check_duplicate_string(info, stack_a) == 0)
		{
			ft_free_stack(stack_a);
			ft_free_mem(info->split_values);
			ft_str_fd("ERROR\n", 2);
		}
	}
	else
	{
		if (ft_check_num(&argv[1]) == 0
			|| ft_check_duplicate_args(argv, stack_a, info) == 0)
		{
			ft_free_stack(stack_a);
			ft_str_fd("ERROR\n", 2);
		}
	}
}

int	ft_check_num(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (j == 0 && argv[i][0] == '-' && argv[i][1])
				j++;
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_duplicate_string(t_arg	*info, t_stack **stack_a)
{
	int	j;
	int	i;

	i = 0;
	if (info->max_size == 0)
		return (0);
	while (info->split_values[i])
	{
		j = 0;
		while (info->split_values[j])
		{
			if (ft_atol(info->split_values[i], 1, stack_a, info)
				== ft_atol(info->split_values[j], 1, stack_a, info) && j != i)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_duplicate_args(char **argv, t_stack **stack_a, t_arg *info)
{
	int	j;
	int	i;

	i = 1;
	while (argv[i])
	{
		j = 1;
		while (argv[j])
		{
			if (ft_atol(argv[i], 2, stack_a, info)
				== ft_atol(argv[j], 2, stack_a, info) && j != i)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_free_stack(t_stack **stack)
{
	t_stack	*head;
	t_stack	*next_s;

	head = *stack;
	while (head)
	{
		next_s = head->next;
		free(head);
		head = next_s;
	}
	*stack = NULL;
}
