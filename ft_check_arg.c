/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriga <abarriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:17:11 by abarriga          #+#    #+#             */
/*   Updated: 2023/02/06 15:40:57 by abarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_arg(char **argv, int argc, t_arg *info)
{
	if (argc < 2)
		ft_error();
	else if (argc == 2)
	{
		info->split_values = ft_split(argv[1], ' ');
		info->max_size = ft_count_arg(info) - 1;
		info->i = info->max_size;
		ft_check_num(info->split_values);
		ft_check_duplicate_string(info);
	}
	else
	{
		ft_check_num(&argv[1]);
		ft_check_duplicate_args(argv);
	}
}

void	ft_check_num(char **argv)
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
			{
				if (argv[i][1] == '0')
					ft_error();
				j++;
			}
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				ft_error();
			j++;
		}
		i++;
	}
}

void	ft_check_duplicate_string(t_arg	*info)
{
	int	j;
	int	i;

	i = 0;
	if (info->max_size == 0)
		ft_error();
	while (info->split_values[i])
	{
		j = 0;
		while (info->split_values[j])
		{
			if (ft_atol(info->split_values[i]) == ft_atol(info->split_values[j]) && j != i)
				ft_error();
			j++;
		}
		i++;
	}
}

void	ft_check_duplicate_args(char **argv)
{
	int	j;
	int	i;

	i = 1;
	while (argv[i])
	{
		j = 1;
		while (argv[j])
		{
			if (ft_atol(argv[i]) == ft_atol(argv[j]) && j != i)
				ft_error();
			j++;
		}
		i++;
	}
}