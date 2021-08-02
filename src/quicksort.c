/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 12:21:43 by bclerc            #+#    #+#             */
/*   Updated: 2021/08/03 01:18:05 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

static void	value_sort(int *value, int len)
{
	long	tmp;
	int		i;

	tmp = 0;
	i = 0;
	i = 0;

	while (i < len - 1)
	{
		if (value[i] <= value[i + 1])
			i++;
		else
		{
			tmp = value[i];
			value[i] = value[i + 1];
			value[i + 1] = tmp;
			i = 0;
		}
	}
}

int get_median(t_stack **stack)
{
	int		*tab;
	int 	i;

	t_stack *tmp;

	tab = malloc((get_stack_size(stack) * sizeof(int)) + 1);
	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tab[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	tab[i] = 0;
	value_sort(tab, i);
	return (tab[i / 2]);
}

// ICI AUTRE FICHIER
int get_high_pos(t_stack **stack)
{
	t_stack *tmp;
	int		pos;
	int		value;
	int		i;

	tmp = *stack;
	pos = 0;
	while (tmp)
	{
		if (tmp->value > value)
			pos = i;
		i++;
		tmp = tmp->next;

	}
	return (i);
}

int get_low_pos(t_stack **stack)
{
	t_stack *tmp;
	int		pos;
	int		value;
	int		i;

	tmp = *stack;
	pos = 0;
	value = 0;
	while (tmp)
	{
		if (tmp->value < value)
			pos = i;
		i++;
		tmp = tmp->next;
	}
	
	return (i);
}
// FIN ICI AUTRE FICHIER

int	sort(t_push *push)
{
	int median;
	int size;
	int i;

	size = get_stack_size(push->stacka);
	median = get_median(push->stacka);
	printf("Median %d\n", get_median(push->stacka));
	i = size;	
	while (size > 0)
	{
		printf("\n| %d < %d| \n", (*push->stacka)->value, median);
		if ((*push->stacka)->value < median)
		{
			pushs(push->stacka, push->stackb);
			printf("pb\n");
			continue ;
		}
		
		rotate(push->stacka);
		printf("ra\n");
		size--;
	}
	while (i > 0)
	{
		int higher = get_high_pos(push->stackb);
		int lower = get_low_pos(push->stackb);
		int total_instruct = 0;
		if (i)
		i-->
	}

















	return (1);
}