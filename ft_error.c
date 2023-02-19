/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alberto <alberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:33:15 by abarriga          #+#    #+#             */
/*   Updated: 2023/02/19 15:36:51 by alberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void	ft_error_input(void)
{
	ft_printf("El programa se ha acabado por un error en la entrada");
	exit(-1);
} */

void	ft_str_fd(char *str, int fd)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(fd, &str[i++], 1);
	}
	exit(-1);
}

char	**ft_free_mem(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (0);
}
