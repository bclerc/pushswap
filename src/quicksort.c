/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 12:21:43 by bclerc            #+#    #+#             */
/*   Updated: 2021/08/23 14:50:53 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int check_if_ra(t_push *push, int part, int median)
{
	t_stack *tmp;

	tmp = *push->stacka;
	while (tmp)
	{
		if (part)
		{
			if (tmp->value > median)
				return (1);
		}
		else
		{
			if (tmp->value < median)
				return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int	sort(t_push *push)
{
	int party;
	int median;
	int size;
	int i = 0;
	size	= 	get_stack_size(push->stacka);
	median	= 	get_median(push->stacka);
	
	party = 0;
	while (party < 2)
	{
		while (size > 0 && check_if_ra(push, party, median))
		{
			if (party == 0)
			{
				if ((*push->stacka)->value <= median)
				{
					pushs(push->stacka, push->stackb);
					ft_putstr("pb\n");
					continue ;
				}
			}
			else if ((*push->stacka)->value > median)
			{
				pushs(push->stacka, push->stackb);
				ft_putstr("pb\n");
				continue ;
			}
			rotate(push->stacka);
			ft_putstr("ra\n");
			size--;
		}
		push->ra = 0;
		while (get_stack_size(push->stackb)  > 0)
		{
			push->size = get_stack_size(push->stackb);
			smart_push_a(push);
			i++;
		}
			i++;
			pushs(push->stackb, push->stacka);
			ft_putstr("pa\n");
			rotate(push->stacka);
			ft_putstr("ra\n");
		while (push->ra > 0)
		{
			rotate(push->stacka);
			ft_putstr("ra\n");
			push->ra--;
		}
		size = i;
		party++;
	}
	return (1);
}