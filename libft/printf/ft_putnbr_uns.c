/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriga <abarriga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:39:10 by abarriga          #+#    #+#             */
/*   Updated: 2022/10/09 13:29:45 by abarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_putnbr_uns(unsigned long n)
{
	long			num;
	unsigned int	len;

	len = 0;
	num = n;
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
