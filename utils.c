/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alberto <alberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:27:45 by alberto           #+#    #+#             */
/*   Updated: 2023/02/07 22:10:38 by alberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_init_order(t_stack   *node)
{
    ft_init_pos_r(node);
}

void    ft_init_pos_r(t_stack *node)
{
    int i;
    int j;
    
    i = 0;
    j = ft_lstsize(node);
    
    while (node->next)
    {
        node->pos_r = i;
        i++;
        node = node->next;
    }
    node->last_pos = j - 1;
}

void    ft_init_pos_ord(t_stack node)
{
        
}

int	ft_lstsize(t_stack *lst)
{
	int	count;

	count = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}