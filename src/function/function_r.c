/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 15:03:29 by bclerc            #+#    #+#             */
/*   Updated: 2021/05/20 15:28:29 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pushswap.h"

int	ra(t_push *push)
{
	t_stack *tmp;
	t_stack *head;
	
	if (push->stacka && push->stacka->next)
	{
		tmp = push->stacka;
		head = push->stacka->next;
		push->stacka = push->stacka->next;
		tmp->next = NULL;
		while (push->stacka->next)
			push->stacka = push->stacka->next;
		push->stacka->next = tmp;
		printf("Value : %d\n", tmp->value);
		push->stacka = head;
		return (1);
	}
	return (0);
}
