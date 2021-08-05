/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 12:21:43 by bclerc            #+#    #+#             */
/*   Updated: 2021/08/05 17:30:41 by bclerc           ###   ########.fr       */
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
	i = 0;
	value = tmp->value;
	while (tmp)
	{
		if (tmp->value > value)
		{
			pos = i;
			value = tmp->value;
		}
		i++;
		tmp = tmp->next;

	}
	return (pos);
}

int get_low_pos(t_stack **stack)
{
	t_stack *tmp;
	int		pos;
	int		value;
	int		i;

	tmp = *stack;
	pos = 0;
	value = tmp->value;
	i = 0;
	while (tmp)
	{
		if (tmp->value < value)
		{
			pos = i;
			value = tmp->value;
		}
		i++;
		tmp = tmp->next;
	}
	
	return (pos);
}

// FIN ICI AUTRE FICHIER

void	do_instruct(t_push *push, t_instruct instruct)
{
	int i;

	i = 0;
	if (instruct.top)
		push->ra = push->ra + 1;
	while (i < instruct.needed)
	{
		if (instruct.type)
		{
			reverse_rotate(push->stackb);
			printf("rrb\n");
		}
		else
		{
			rotate(push->stackb);
			printf("rb\n");
		}
		i++;
	}
	pushs(push->stackb, push->stacka);
	printf("pa\n");
	if (!instruct.top)
	{
		rotate(push->stacka);
		printf("ra\n");
	}
}

	// 0 : rb, 1 : rrb 
	//printf("| Higher: %d (%s) Lower: %d (%s)| |Instruction %s for %d mv\n",higher_instruct.needed,higher_instruct.type == 0 ? "rb" : "rrb", lower_instruct.needed, lower_instruct.type == 0 ? "rb" : "rrb", final_instruct.type == 0 ? "rb" : "rrb", final_instruct.needed);
int smart_push_a(t_push *push)
{
		int higher = get_high_pos(push->stackb) ;
		int lower = get_low_pos(push->stackb) ;
		t_instruct higher_instruct;
		t_instruct lower_instruct;
		t_instruct final_instruct;

	higher_instruct.top = 1;
	if (higher  < (push->size / 2))
	{	
		higher_instruct.needed = higher;
		higher_instruct.type = 0;
	}
	else
	{

		higher_instruct.needed = ft_abs(push->size - higher) + 1;
		higher_instruct.type = 1;
	}
	lower_instruct.top = 0;
	if (lower  < (push->size / 2))
	{
		lower_instruct.needed = lower;
		lower_instruct.type = 0;
	}
	else
	{
		lower_instruct.needed = ft_abs(push->size - lower) + 1;
		lower_instruct.type = 1;
	}
	if (higher_instruct.needed > lower_instruct.needed)
		final_instruct = lower_instruct;
	else
		final_instruct = higher_instruct;
	do_instruct(push, final_instruct);
}

int	sort(t_push *push)
{
	int party;
	int median;
	int size;
	int i;
	size	= 	get_stack_size(push->stacka);
	median	= 	get_median(push->stacka);
	
	party = 0;
	while (party < 2)
	{
		while (size > 0)
		{
			if (party == 0)
			{
				if ((*push->stacka)->value <= median)
				{
					pushs(push->stacka, push->stackb);
					printf("pb\n");
					continue ;
				}
			}
			else if ((*push->stacka)->value > median)
			{
				pushs(push->stacka, push->stackb);
				printf("pb\n");
				continue ;
			}
			rotate(push->stacka);
			printf("ra\n");
			size--;
		}
		push->ra = 0;
		while (get_stack_size(push->stackb)  > 0)
		{
			push->size = get_stack_size(push->stackb);
			smart_push_a(push);
			i++;
		}
			pushs(push->stackb, push->stacka);
			rotate(push->stacka);
			printf("ra\n");
		while (push->ra > 0)
		{
			rotate(push->stacka);
			printf("ra\n");
			push->ra--;
		}
		size = i;
		party++;
	}
	return (1);
}