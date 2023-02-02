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

int	main(int argc, char **argv);

t_stack *ft_init_stacks(t_stack **first, int value);

void	print_list(t_stack *first);

int	ft_atoi(const char *str);

#endif