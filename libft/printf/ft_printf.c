/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriga <abarriga@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 12:28:45 by abarriga          #+#    #+#             */
/*   Updated: 2022/10/09 13:35:25 by abarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static unsigned int	ft_conversions(const char c, va_list args)
{
	unsigned int	len;

	len = 0;
	if (c == 'c')
		len = ft_putchar(va_arg(args, int));
	else if (c == 's')
		len = ft_putstr(va_arg(args, char *));
	else if (c == 'p')
	{
		len = ft_putstr("0x");
		len = len + ft_puthexap("0123456789abcdef",
				va_arg(args, unsigned long));
	}
	else if (c == 'd' || c == 'i')
		len = ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		len = ft_putnbr_uns(va_arg(args, unsigned int));
	else if (c == 'x')
		len = ft_puthexa("0123456789abcdef", va_arg(args, unsigned long));
	else if (c == 'X')
		len = ft_puthexa("0123456789ABCDEF", va_arg(args, unsigned long));
	else if (c == '%')
		len = ft_putchar('%');
	return (len);
}

int	ft_printf(char const *str, ...)
{
	va_list			args;
	unsigned int	len;
	unsigned int	i;

	len = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			len = len + ft_conversions(str[i + 1], args);
			i++;
		}
		else
			len = len + ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
