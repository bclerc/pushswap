/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_rr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 13:43:25 by bclerc            #+#    #+#             */
/*   Updated: 2021/06/15 15:14:48 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

int	rra(t_push *push)
{
	t_stack *tmp;
	t_stack *head;

	head = push->stacka;
	while (push->stacka->next)
	{
		tmp = push->stacka;
		push->stacka = push->stacka->next;
	}
	tmp->next = NULL;
	push->stacka->next = head;
	return (1);
}

int	rrb(t_push *push)
{
	t_stack *tmp;
	t_stack *head;

	head = push->stackb;
	while (tmp->next)
	{
		tmp = head->next;
		push->stackb = push->stackb->next;
	}
	tmp->next = NULL;
	push->stackb = head;
	return (1);
}

int	rrr(t_push *push)
{
	rra(push);
	rrb(push);
	return (1);
}