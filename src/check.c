/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 14:54:06 by bclerc            #+#    #+#             */
/*   Updated: 2021/08/30 14:33:47 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	readList(t_stack *stack)
{
	t_stack	*tmp;

	if (stack == NULL)
	{
		printf("Empty stack\n");
		return ;
	}
	tmp = stack;
	while (tmp->next)
	{
		ft_putnbr(tmp->value);
		ft_putchar(' ');
		tmp = tmp->next;
	}
	ft_putnbr(tmp->value);
	ft_putchar(' ');
	printf("\n");
}

void	free_stack(t_stack *stack)
{
	if (stack)
	{
		if (stack->next)
			free_stack(stack->next);
		free(stack);
		stack = NULL;
	}
}

void	exit_error()
{
	printf("Error\n");
	exit(1);
}

int	is_in_stack(int value, t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->value == value)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
