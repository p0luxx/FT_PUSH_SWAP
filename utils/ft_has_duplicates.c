/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_has_duplicates.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorkgall <gorkgall@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 13:55:52 by gorkgall          #+#    #+#             */
/*   Updated: 2026/05/02 14:23:01 by gorkgall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_has_duplicates(t_stack *a)
{
	t_node	*current;
	t_node	*check;

	if (!a || !a->top)
		return (0);
	current = a->top;
	while (current)
	{
		check = current->next;
		while (check)
		{
			if (current->value == check->value)
			{
				printf("tiene duplicados");
				return (1);
				
			}
			check = check->next;
		}
		current = current->next;
	}
	return (0);
}
