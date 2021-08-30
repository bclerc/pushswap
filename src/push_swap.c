/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:01:06 by bclerc            #+#    #+#             */
/*   Updated: 2021/08/30 14:39:20 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	isNumber(char *number)
{
	int	i;

	i = 0;
	while (number[i])
	{
		if (!ft_isdigit(number[i]) && (number[i] != '-'))
			return (0);
		i++;
	}
	return (1);
}

int	add_value_to_stack(t_stack *stack, t_stack *stack2)
{
	t_stack	*tmp;

	tmp = stack2;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = stack;
	return (1);
}

t_stack	*createstack(int argc, char **argv)
{
	int		i;
	t_stack	*list;
	t_stack	*tmp;

	list = 0;
	i = 1;
	while (i < argc)
	{
		if (!isNumber(argv[i]))
			exit_error(NULL, "Please insert only numbers");
		if (is_in_stack(ft_atoi(argv[i]), &list))
			exit_error(NULL, "Duplicate number");
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

void	dispatch(int argc, t_push *push)
{
	if (argc < 6 && argc > 2)
		three_sort(push->stacka);
	if (argc == 6)
		five_sort(push);
	if (argc > 6 && argc < 400)
		sort(push);
	if (argc > 400)
		big_sort(push);
}

int	main(int argc, char **argv)
{
	t_push	*push;
	t_stack	*stacka;
	t_stack	*stackb;

	push = malloc(sizeof(t_push));
	if (argc < 2)
	{
		exit_error();
		return (-1);
	}
	stacka = createstack(argc, argv);
	stackb = createstack(0, NULL);
	push->stacka = &stacka;
	push->stackb = &stackb;
	if (!check_sort(stacka))
		dispatch(argc, push);
	free_stack(*push->stacka);
	free_stack(*push->stackb);
	free(push);
	return (1);
}
