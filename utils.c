/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alberto <alberto@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:27:45 by abarriga          #+#    #+#             */
/*   Updated: 2023/02/19 01:41:16 by alberto          ###   ########.fr       */
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
	t_var	var;
	t_stack	*node;

	ft_init_variables_init_pos_ord(&var);
	node = top;
	while (var.i <= ft_stacksize(top))
	{
		var.min = INT_MAX;
		while (node)
		{
			if ((node->value < var.min && (node->value > var.last))
				|| (node->value == INT_MIN && var.j == 0))
			{
				if (node->value == INT_MIN)
					var.j = 1;
				var.min = node->value;
			}
			node = node->next;
		}
		var.last = var.min;
		node = get_node(top, var.min);
		node->index = var.i++;
		node = top;
	}
}

void	ft_init_variables_init_pos_ord(t_var *var)
{
	var->i = 1;
	var->j = 0;
	var->last = INT_MIN;
}
