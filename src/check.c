/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 14:54:06 by bclerc            #+#    #+#             */
/*   Updated: 2021/08/24 16:01:44 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	exit_error(t_push *push, char *msg)
{
	printf("Error\n%s\n", msg);
	exit(1);
}

int is_in_stack(int value, t_stack **stack)
{
	t_stack *tmp;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->value == value)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
