/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 14:41:07 by bclerc            #+#    #+#             */
/*   Updated: 2021/08/30 19:29:51 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

t_median	get_all_median(t_stack **stack)
{
	int			*tab;
	int			i;
	t_stack		*tmp;
	t_median	median;

	tab = malloc(((get_stack_size(stack) + 1) * sizeof(int)));
	if (!tab)
		exit(1);
	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tab[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	value_sort(tab, i);
	i = i / 4;
	median.quarter = tab[i];
	median.median = tab[i * 2];
	median.three_quarter = tab[i * 3];
	free(tab);
	tmp = NULL;
	return (median);
}

int	get_median(t_stack **stack)
{
	int		*tab;
	int		i;
	t_stack	*tmp;

	tab = (int *)malloc(((get_stack_size(stack) + 1) * sizeof(int)));
	if (!tab)
		exit(1);
	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tab[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	value_sort(tab, i);
	i = tab[i / 2];
	free(tab);
	tmp = NULL;
	return (i);
}
