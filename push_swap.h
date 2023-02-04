/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriga <abarriga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:04:44 by abarriga          #+#    #+#             */
/*   Updated: 2023/02/04 15:46:35 by abarriga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	int	value;
	struct s_stack *next;
}					t_stack;
typedef struct s_arg
{
	char	**split_values;
	int		max_size;
	int		i;
}				t_arg;

int	main(int argc, char **argv);

t_stack *ft_init_stacks(t_stack **first, int value);

void	print_list(t_stack *first);

int	ft_atoi(const char *str);

void	ft_stack_string (char **argv, t_stack **stack_a, t_arg *info);

int	ft_count_arg(t_arg	*info);

void	*ft_bzero(void *s, size_t n);

void	*ft_calloc(size_t count, size_t size);

int	ft_count_words(char const *s, char c);

char	**ft_split(char const	*s, char c);

#endif