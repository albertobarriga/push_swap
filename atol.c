/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alberto <alberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:05:55 by abarriga          #+#    #+#             */
/*   Updated: 2023/02/18 20:43:14 by alberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atol(const char *str)
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
	ft_check_atol(res);
	return ((int)res);
}

void	ft_check_atol(long res)
{
	if (res > INT_MAX)
		ft_error_input();
	if (res < INT_MIN)
		ft_error_input();
}
