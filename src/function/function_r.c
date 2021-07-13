/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:03:29 by bclerc            #+#    #+#             */
/*   Updated: 2021/07/13 15:04:48 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

int	ra(t_push *push)
{
	t_stack	*tmp;
	t_stack	*head;

	if (push->stacka && push->stacka->next)
	{
		tmp = push->stacka;
		head = push->stacka->next;
		push->stacka = push->stacka->next;
		tmp->next = NULL;
		while (push->stacka->next)
			push->stacka = push->stacka->next;
		push->stacka->next = tmp;
		push->stacka = head;
		return (1);
	}
	return (0);
}

int	rb(t_push *push)
{
	t_stack	*tmp;
	t_stack	*head;

	if (push->stackb && push->stackb->next)
	{
		tmp = push->stackb;
		head = push->stackb->next;
		push->stackb = push->stackb->next;
		tmp->next = NULL;
		while (push->stackb->next)
			push->stackb = push->stackb->next;
		push->stackb->next = tmp;
		push->stackb = head;
		return (1);
	}
	return (0);
}

void	rr(t_push *push)
{
	ra(push);
	rb(push);
}
