/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_rr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 13:43:25 by bclerc            #+#    #+#             */
/*   Updated: 2021/07/28 19:26:53 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

int	reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*head;

	head = *stack;
	while ((*stack)->next)
	{
		tmp = *stack;
		*stack = (*stack)->next;
	}
	tmp->next = NULL;
	(*stack)->next = head;
	return (1);
}

int	rrr(t_push *push)
{
	reverse_rotate(push->stacka);
	reverse_rotate(push->stackb);
	return (1);
}
