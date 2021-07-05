/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclerc <bclerc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 12:50:17 by bclerc            #+#    #+#             */
/*   Updated: 2021/06/28 13:00:12 by bclerc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	stackdelone(t_stack *alst)
{
	if (!alst)
		return;
	free(alst);
	alst = NULL;
}

void	stackdel(t_stack *alst)
{
	if (!alst)
		return ;
	while ((alst)->next)
		stackdel(alst->next);
	stackdelone(alst);
}

