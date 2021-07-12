/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 13:00:42 by bclerc            #+#    #+#             */
/*   Updated: 2021/07/12 04:24:19 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"
void sort_f(int b, t_push *push)
{
	while (b > 0)
	{
		rra(push);
		b--;
	}
	pa(push);
	printf(" ");
}
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
	sort_f(push->sizea - i, push);
}
