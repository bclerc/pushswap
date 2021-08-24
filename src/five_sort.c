/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 20:06:34 by bclerc            #+#    #+#             */
/*   Updated: 2021/08/24 20:09:06 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int		check_insert(int value, t_stack **stack)
{
	t_stack *tmp;
	int i;

	i = 0;
	tmp = *stack;
	while (tmp->next)
	{
		if (i == 0 && value < tmp->value)
			return (0);
		if (value > tmp->value && value < tmp->next->value)
			return (i + 1);
		tmp = tmp->next;
		i++;
	}
	return -1;
}
void	_sort(t_push *push, int insert_pos)
{
	int i;

	i = 0;
	if (insert_pos == -1)
	{
		pushs(push->stackb, push->stacka);
		rotate(push->stacka);
		printf("pa\nra\n");
	}
	else
	{
		while (i < insert_pos)
		{
			printf("ra\n");
			rotate(push->stacka);
			i++;
		}
		printf("pa\n");
		pushs(push->stackb, push->stacka);
		if (insert_pos > 0)
		{
			while (insert_pos > 0)
			{
				printf("rra\n");
				reverse_rotate(push->stacka);
				insert_pos--;
			}
		}
	}
}

void	five_sort(t_push *push)
{
	int	i;
	int	insert_pos;

	pushs(push->stacka, push->stackb);
	pushs(push->stacka, push->stackb);
	printf("pb\npb\n");
	three_sort(push->stacka);
	i = 2;
	while (i > 0)
	{
		insert_pos = check_insert((*push->stackb)->value, push->stacka);
		_sort(push, insert_pos);
		i--;
	}
}
