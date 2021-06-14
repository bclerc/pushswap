/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_rr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 13:43:25 by bclerc            #+#    #+#             */
/*   Updated: 2021/06/14 16:26:34 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

int	rra(t_push *push)
{	
	t_stack *tmp;
	t_stack *head;

	head = push->stacka;
	tmp = head->next;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	push->stacka = head->next;
	tmp->next = head;
	head->next = NULL;

	return (1);
}

int	rrb(t_push *push)
{

	t_stack *tmp;
	t_stack *head;

	head = push->stackb;
	tmp = head->next;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	push->stackb = head->next;
	tmp->next = head;
	head->next = NULL;

	return (1);


	return (1);
}

int	rrr(t_push *push)
{
	rra(push);
	rrb(push);
	return (1);
}