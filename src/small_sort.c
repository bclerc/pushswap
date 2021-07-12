/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 13:00:42 by bclerc            #+#    #+#             */
/*   Updated: 2021/07/12 03:13:57 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void  small_sort(t_push *push)
{
	int i;
	int b;
	int value;
	t_stack *link;
	t_stack *tmp;

	if (push->sizea > 5)
		return ;
	i = 0;
	b = 0;
	tmp = push->stacka;
	value = 9000;
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
	b = push->sizea - i;
	while (b > 0)
	{
		rra(push);
		b--;
	}
	i = 0;
	pa(push);
	printf("1");
}