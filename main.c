int main(int argc, char **argv)
{
	int	i;
	char *a;

	if (argc < 1)
	{
		return(0);
	}
	if ()
	{
		init_stack();
	}
	else if (init_stack())
	i = 0;
	while (i < argc)
	{
		lst->content = ft_atoi(argv[i + 1])
		a[i] = ft_atoi(argv[i + 1]);
		if (a[i] > max_iter || a[i] < min_iter || ft_atoi[i + 1] = "ERROR")
			return (ERROR);
		i++;
	}
}

int	init_stack(int argc, char **argv, t_stack)
{
	stack_size = lenght_stack(argc, argv);
	if (!stack_a->string = malloc(sizeof(int) * stack_size))
		return (ERROR);
	if (!stack_b->string = malloc(sizeof(int) * stack_size))
	{
		free(stack_a->string);
		return (ERROR);
	}
}

size_t	lenght_stack(int argc, char **argv)
{
	size_t i;
	
	size = 0;
	i = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if ((!j || argv[i][j - 1] == ' ') && argv[i][j] != ' ')
				size++;
			j++;
		}
		i++;
	}
	return (size);
}

int	ft_atoi(const char *str)
{
	int	s;
	int	res;
	int	i;

	s = 1;
	res = 0;
	i = 0;
	// while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
	// 	i++;
	if (!(str[i] >= '0' && str[i] <= '9' && str[i] == '-'))
	{
		return (ERROR);
	}
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

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*list;

	if (*lst)
	{
		list = ft_lstlast(*lst);
		list->next = new;
	}
	else
		*lst = new;
}

t_stack	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}