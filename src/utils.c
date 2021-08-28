/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 23:47:23 by bclerc            #+#    #+#             */
/*   Updated: 2021/08/28 19:36:08 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	value_sort(int *value, int len)
{
	long	tmp;
	int		i;

	tmp = 0;
	i = 0;
	i = 0;
	while (i < len - 1)
	{
		if (value[i] <= value[i + 1])
			i++;
		else
		{
			tmp = value[i];
			value[i] = value[i + 1];
			value[i + 1] = tmp;
			i = 0;
		}
	}
}

int	get_stack_size(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *stack;
	while (tmp->next)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	check_sort(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	get_high_pos(t_stack **stack)
{
	t_stack	*tmp;
	int		pos;
	int		value;
	int		i;

	tmp = *stack;
	pos = 0;
	i = 0;
	value = tmp->value;
	while (tmp)
	{
		if (tmp->value > value)
		{
			pos = i;
			value = tmp->value;
		}
		i++;
		tmp = tmp->next;
	}
	return (pos);
}

int	get_low_pos(t_stack **stack)
{
	t_stack	*tmp;
	int		pos;
	int		value;
	int		i;

	tmp = *stack;
	pos = 0;
	value = tmp->value;
	i = 0;
	while (tmp)
	{
		if (tmp->value < value)
		{
			pos = i;
			value = tmp->value;
		}
		i++;
		tmp = tmp->next;
	}	
	return (pos);
}
