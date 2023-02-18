/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alberto <alberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:27:45 by abarriga          #+#    #+#             */
/*   Updated: 2023/02/18 20:45:39 by alberto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_order(t_stack *node)
{
	ft_init_pos_r(node);
	ft_init_pos_ord(node);
}

void	ft_init_pos_r(t_stack *node)
{
	int	i;

	i = 0;
	while (node)
	{
		node->pos_r = i;
		i++;
		node = node->next;
	}
}

t_stack	*get_node(t_stack *node, int value)
{
	while (node)
	{
		if (node->value == value)
			return (node);
		node = node->next;
	}
	return (NULL);
}

void	ft_init_pos_ord(t_stack *top)
{
	int		min;
	int		last;
	int		i;
	int		j;
	t_stack	*node;

	i = 1;
	j = 0;
	last = INT_MIN;
	node = top;
	while (i <= ft_stacksize(top))
	{
		min = INT_MAX;
		while (node)
		{
			if ((node->value < min && (node->value > last))
				|| (node->value == INT_MIN && j == 0))
			{
				if (node->value == INT_MIN)
					j = 1;
				min = node->value;
			}
			node = node->next;
		}
		last = min;
		node = get_node(top, min);
		node->index = i++;
		node = top;
	}
}

int	ft_stacksize(t_stack *lst)
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
