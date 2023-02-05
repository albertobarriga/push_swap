/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriga <abarriga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 13:26:19 by abarriga          #+#    #+#             */
/*   Updated: 2022/10/09 13:36:15 by abarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

unsigned int	ft_puthexap(const char *str, unsigned long long n)
{
	unsigned int	len;

	len = 0;
	if (n >= 16)
	{
		len = len + ft_puthexap(str, n / 16);
		len = len + ft_puthexap(str, n % 16);
	}
	else
	{
		ft_putchar(str[n]);
		len++;
	}
	return (len);
}
