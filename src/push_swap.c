/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:01:06 by bclerc            #+#    #+#             */
/*   Updated: 2021/05/17 15:43:09 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pushswap.h"

t_stack	*lstnew(void const *value)
{
	t_stack *list;

	if (!(list = malloc(sizeof(t_list))))
		return (NULL);
	if (!value)
	{
		list->value = 0;
		list->next = NULL;
		return (list);
	}
	if (!(list->value =(int)malloc(sizeof(int))))
		return (NULL);
	ft_memcpy((void*)list->value, value, 1);
	list->value = 0;
	list->next = NULL;
	return (list);
}

int add(int number, t_stack **stack)
{
	t_stack *new;

	new = (t_stack *)malloc(sizeof(t_stack));
	new->value = number;	
	if (stack != NULL && new != NULL)
	{

		new->next = *stack;
		*stack = new;
		printf("added %d\n", number);
		return (1);
	}
	return (0);
}

int parse(char **argv, t_stack **stack, t_push *push)
{
	int i;
	int x;
	i = 0;
	while(argv[i])
	{	
		x = 0;
		while (argv[i][x])
		{
			if (argv[i][x] == ' ' || argv[i][x] == '\n')
				continue ;
			if (ft_isdigit(argv[i][x]))
			{
				add(argv[i][x] - '0', stack);
				push->totalnumber++;
			}
			else
			{
				printf("%c is not a integer. Please use only integer", argv[i][x]);
				return (0);
			}
			x++;
		}
		i++;
	}
	return (1);
}


void readList(t_stack *stack, t_push push)
{
	t_stack *tmp;

	tmp = stack;
	while (push.totalnumber > 0)
	{
		ft_putnbr(tmp->value);
		tmp = tmp->next;
		push.totalnumber--;
	}
}

int main(int argc, char **argv)
{
	t_stack *stacka;
	t_stack *stackb;
	t_push push;

	push.totalnumber = 0;
	if (argc < 2)
	{
		printf("Please insert a lot of numbers");
		return (-1);
	}
	
	stacka = lstnew(0);
	stackb = (t_stack*)malloc(argc * sizeof(t_stack));
	parse(argv + 1, &stacka, &push);
	readList(stacka, push);
	return (1);
}
