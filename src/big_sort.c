/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 14:29:47 by bclerc            #+#    #+#             */
/*   Updated: 2021/08/25 16:52:50 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	check_if_ra_b(t_push *push, int part, int *i, t_median median)
{
	t_stack	*tmp;

	tmp = *push->stacka;
	while (tmp)
	{
		if (part == 0 && tmp->value <= median.quarter)
			return (1);
		if (part == 1 && tmp->value > median.quarter
			&& tmp->value <= median.median)
			return (1);
		if (part == 2 && tmp->value > median.median
			&& tmp->value <= median.three_quarter)
			return (1);
		if (part == 3 && tmp->value > median.three_quarter)
			return (1);
		tmp = tmp->next;
	}

	if (*i > 0)
	{
		(*i)--;
		return (1);
	}
	return (0);
}

int	push_median_bb_s(t_push *push, int *size, int party, t_median median)
{
	if (party == 2 && (*push->stacka)->value > median.median
		&& (*push->stacka)->value <= median.three_quarter)
	{
		pushs(push->stacka, push->stackb);
		ft_putstr("pb\n");
		return (1);
	}
	else if (party == 3 && (*push->stacka)->value > median.three_quarter)
	{
		pushs(push->stacka, push->stackb);
		ft_putstr("pb\n");
		return (1);
	}
	return (0);
}

void	push_median_bb(t_push *push, int *size, int party, t_median median)
{
	int i;

	i = push->tried;
	while (*size > 0 && check_if_ra_b(push, party, &i, median))
	{
		if (party == 0 && (*push->stacka)->value <= median.quarter)
		{
			pushs(push->stacka, push->stackb);
			ft_putstr("pb\n");
			continue ;
		}
		else if (party == 1 && (*push->stacka)->value > median.quarter
			&& (*push->stacka)->value <= median.median)
		{
			pushs(push->stacka, push->stackb);
			ft_putstr("pb\n");
			continue ;
		}
		else if (push_median_bb_s(push, size, party, median))
			continue ;
		rotate(push->stacka);
		ft_putstr("ra\n");
		(*size)--;
	}
}

int	big_sort(t_push *push)
{
	t_median	median;
	int			party;
	int			size;
	int			i;

	i = 0;
	median = get_all_median(push->stacka);
	push->tried = 0;
	party = 0;
	size = get_stack_size(push->stacka);
	while (party < 4)
	{
	size = get_stack_size(push->stacka);
		push_median_bb(push, &size, party, median);
		push->ra = 0;
		repush_a(push, &i);
		size = i;
		party++;
	}
	return (1);
}
