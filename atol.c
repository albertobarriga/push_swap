/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriga <abarriga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:05:55 by abarriga          #+#    #+#             */
/*   Updated: 2023/02/22 11:09:23 by abarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atol(const char *str, int flag, t_stack **stack_a, t_arg *info)
{
	long	s;
	long	res;
	long	i;

	s = 1;
	res = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s = s * (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	res = res * s;
	ft_check_atol(res, flag, stack_a, info);
	return ((int)res);
}

void	ft_check_atol(long res, int flag, t_stack **stack_a, t_arg *info)
{
	if (flag == 1)
	{
		if (res > INT_MAX || res < INT_MIN)
		{
			ft_free_stack(stack_a);
			ft_free_mem(info->split_values);
			ft_str_fd("ERROR\n", 2);
		}
	}
	else if (flag == 2)
	{
		if (res > INT_MAX || res < INT_MIN)
		{
			ft_free_stack(stack_a);
			ft_str_fd("ERROR\n", 2);
		}	
	}
}
