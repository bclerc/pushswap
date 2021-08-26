/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 14:50:13 by bclerc            #+#    #+#             */
/*   Updated: 2021/08/26 15:50:38 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

t_stack	*get_last(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	do_instruct(t_push *push, t_instruct instruct)
{
	int	i;

	i = -1;
	if (instruct.top)
		push->ra = push->ra + 1;
	while (++i < instruct.needed)
	{
		if (instruct.type)
		{
			reverse_rotate(push->stackb);
			ft_putstr("rrb\n");
		}
		else
		{
			rotate(push->stackb);
			ft_putstr("rb\n");
		}
	}
	pushs(push->stackb, push->stacka);
	ft_putstr("pa\n");
	if (!instruct.top)
	{
		rotate(push->stacka);
		ft_putstr("ra\n");
	}
}

t_instruct	get_lower_instruct(t_push *push)
{
	t_instruct	lower_instruct;
	int			lower;

	lower = get_low_pos(push->stackb);
	lower_instruct.top = 0;
	if (lower < (push->size / 2))
	{
		lower_instruct.needed = lower;
		lower_instruct.type = 0;
	}
	else
	{
		lower_instruct.needed = ft_abs(push->size - lower) + 1;
		lower_instruct.type = 1;
	}
	return (lower_instruct);
}

void	smart_push_a(t_push *push)
{
	int			higher;
	t_instruct	higher_instruct;
	t_instruct	lower_instruct;
	t_instruct	final_instruct;

	higher = get_high_pos(push->stackb);
	higher_instruct.top = 1;
	if (higher < (push->size / 2))
	{	
		higher_instruct.needed = higher;
		higher_instruct.type = 0;
	}
	else
	{
		higher_instruct.needed = ft_abs(push->size - higher) + 1;
		higher_instruct.type = 1;
	}
	lower_instruct = get_lower_instruct(push);
	if (higher_instruct.needed > lower_instruct.needed)
		final_instruct = lower_instruct;
	else
		final_instruct = higher_instruct;
	do_instruct(push, final_instruct);
}
