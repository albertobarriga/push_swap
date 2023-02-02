#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	int			i;

	stack_a = NULL;
	stack_b = NULL;
	i = argc;
	if (argc >= 2)
	{
		while (i > 1)
		{
			ft_init_stacks(&stack_a, ft_atoi(argv[i - 1]));
			i--;
		}
	}
	print_list(stack_a);
}

t_stack	*ft_init_stacks(t_stack **first, int value)
{
	t_stack	*new_node;

	new_node = (t_stack *)(malloc(sizeof(t_stack) * 2));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = *first;
	*first = new_node;
	return (*first);
}

void	print_list(t_stack *first)
{
	

	while (first->next)
	{

		printf("imprime  %i\n", first->value);
		
		first = first->next;
	}
	printf("imprime  %i\n", first->value);
}

int	ft_atoi(const char *str)
{
	int	s;
	int	res;
	int	i;

	s = 1;
	res = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
	i++;
	// if (!(str[i] >= '0' && str[i] <= '9' && str[i] == '-'))
	// {
	// 	return (0);
	// }
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s = s * (-1);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	res = res * s;
	return (res);
}