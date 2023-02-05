/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriga <abarriga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:27:05 by abarriga          #+#    #+#             */
/*   Updated: 2022/10/09 13:37:48 by abarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_putnbr(int n)
{
	long			num;
	unsigned int	len;

	len = 0;
	num = n;
	if (num < 0)
	{
		ft_putchar('-');
		len++;
		num = num * (-1);
	}
	if (num < 10)
	{
		ft_putchar(num + '0');
		len++;
	}
	else
	{
		len = len + ft_putnbr(num / 10);
		ft_putchar((num % 10) + '0');
		len++;
	}
	return (len);
}
