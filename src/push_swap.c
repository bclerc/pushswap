/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:01:06 by bclerc            #+#    #+#             */
/*   Updated: 2021/07/27 19:43:21 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

// Y a pas de norme je sais

t_stack *lstnew(void const *value)
{
	t_stack *list;
	if (!(list = malloc(sizeof(t_list))))
		return (NULL);
	if (!value)
	{
		list->value = (int)value;
		list->next = NULL;
		return (list);
	}
	if (!(list->value = (int)malloc(sizeof(int))))
		return (NULL);
	ft_memcpy((void *)list->value, value, 1);
	list->value = 0;
	list->next = NULL;
	return (list);
}

int add(int number, t_stack **stack)
{
	t_stack *new;

	new = (t_stack *)malloc(sizeof(t_stack));
	new->value = number;
	if (stack == NULL)
	{
		*stack = lstnew((void *)number);
		while (1)
			;
	}
	if (stack != NULL && new != NULL)
	{
		new->next = *stack;
		*stack = new;
		return (1);
	}
	return (0);
}

int isNumber(char *number)
{
	int i;

	i = 0;
	while (number[i])
	{
		if (!ft_isdigit(number[i]) && (number[i] != '-'))
			return (0);
		i++;
	}
	return (1);
}

int add_value_to_stack(t_stack *stack, t_stack *stack2)
{
	t_stack *tmp;

	tmp = stack2;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = stack;
	return (1);
}

t_stack *createstack(int argc, char **argv)
{
	int i;
	t_stack *list;
	t_stack *tmp;

	list = 0;
	i = 1;
	while (i < argc)
	{

		tmp = (t_stack *)malloc(sizeof(t_stack));
		tmp->value = ft_atoi(argv[i]);
		tmp->next = NULL;
		if (!list)
			list = tmp;
		else
		{
			add_value_to_stack(tmp, list);
		}
		i++;
	}

	return (list);
}

int parse(char **argv, t_stack **stack, t_push *push)
{
	int i;
	int x;

	i = push->argc - 2;
	while (i >= 0)
	{
		if (isNumber(argv[i]))
		{
			add(ft_atoi(argv[i]), stack);
			push->sizea++;
			push->totalnumber++;
		}
		else
		{
			printf("%s is not a integer. Please use only integer", argv[i]);
			return (0);
		}
		i--;
	}
	return (1);
}

void readList(t_stack *stack)
{
	t_stack *tmp;

	if (stack == NULL)
	{
		printf("Empty stack\n");
		return;
	}
	tmp = stack;
	while (tmp->next)
	{
		ft_putnbr(tmp->value);
		ft_putchar(' ');
		tmp = tmp->next;
	}
	ft_putnbr(tmp->value);
	ft_putchar(' ');
	printf("\n");
}

int patest(t_stack *stack, t_stack *stackb)
{
	t_stack *tmp;

	if (!stack)
		return 0;
	tmp = stack;
	stack = stack->next;
	add(tmp->value, &stackb);
	if (!stack)
		stack = NULL;
	return (1);
}

int main(int argc, char **argv)
{
	t_push push;

	push.argc = argc;
	push.totalnumber = 0;
	if (argc < 2)
	{
		printf("Please insert a lot of numbers");
		return (-1);
	}
	push.stacka = createstack(argc, argv);
	push.stackb = createstack(0, NULL);
	readList(push.stacka);
	readList(push.stackb);

	//push.stackb = 0;
	//parse(argv + 1, &push.stacka, &push);
	//printf("Stack : a ");
	//readList(push.stacka);
	//printf("Stack : b ");
	//readList(push.stackb);
	//printf("\n ---- Après pointeur test ----\n");
	//patest(&push.stacka, &push.stackb);
	//printf("Stack : a ");
	//readList(push.stacka);
	//printf("Stack : b ");
	//readList(push.stackb);

	//int b = 5;
	//if (argc < 5)
	//{
	//	three_sort(&push);
	//	readList(push.stacka);
	//}
	return (1);
}
