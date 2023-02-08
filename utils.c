/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriga <abarriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:27:45 by alberto           #+#    #+#             */
/*   Updated: 2023/02/08 14:04:25 by abarriga         ###   ########.fr       */
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
	int i;
	int j;

	i = 0;
	j   = ft_stacksize(node);
	while (node->next)
	{
		node->pos_r = i;
		i++;
		node = node->next;
	}
	node->last_pos = j - 1;
}

t_stack *get_node(t_stack *node, int value)
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
	t_stack	*node;

	i = 0;
	last = INT_MIN;
	node = top;
	while (i < ft_stacksize(top))
	{
		min = INT_MAX;
		while (node)
		{
			if (node->value < min && (node->value > last))
				min = node->value;
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