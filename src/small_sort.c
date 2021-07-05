/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 13:00:42 by bclerc            #+#    #+#             */
/*   Updated: 2021/06/28 14:44:47 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/pushswap.h"

int small_sort(t_push *push)
{
	int i;
	int b;
	int value;
	t_stack *link;
	t_stack *tmp;

	if (push->sizea > 5)
		return (0);
	i = 0;
	b = 0;
	tmp = push->stacka;
	while (b < push->sizea)
	{	
		if (tmp->value < value)
		{
			link = tmp;
			value = tmp->value;
			i = b;
		}
		tmp = tmp->next;
		b++;
	}
	printf("\n -------------> %d Position : %d Ra: %d\n", value, i, push->sizea - i);
	b = push->sizea - i;
	while (b > 0)
	{
		rra(push);
		b--;
	}
	i = 0;
	pa(push);
	readList(push->stacka, push);
	if (push->sizea > 0)
		small_sort(push);
	return (1);
}