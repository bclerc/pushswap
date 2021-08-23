/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 14:29:47 by bclerc            #+#    #+#             */
/*   Updated: 2021/08/23 14:42:45 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	big_sort(t_push *push)
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