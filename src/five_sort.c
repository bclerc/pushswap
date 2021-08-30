/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 20:06:34 by bclerc            #+#    #+#             */
/*   Updated: 2021/08/30 18:22:59 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	_insert(t_push *push, int b, int value)
{
	while ((*push->stacka)->value != value)
	{
		if (b < 3)
		{
			printf("ra\n");
			rotate(push->stacka);
		}
		else
		{
			printf("rra\n");
			reverse_rotate(push->stacka);
		}
	}
	printf("pb\n");
	pushs(push->stacka, push->stackb);
}

void	push_smallest(t_push *push)
{
	int		value;
	int		i;
	int		b;
	t_stack	*tmp;

	i = 0;
	b = 0;
	value = (*push->stacka)->value;
	tmp = *push->stacka;
	while (tmp)
	{
		if (tmp->value < value)
		{
			b = i;	
			value = tmp->value;
		}
		tmp = tmp->next;
		i++;
	}
	_insert(push, b, value);
}

void	five_sort(t_push *push)
{
	push_smallest(push);
	push_smallest(push);
	three_sort(push->stacka);
	pushs(push->stackb, push->stacka);
	pushs(push->stackb, push->stacka);
	printf("pa\npa\n");
}
