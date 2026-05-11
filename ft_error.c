/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smilitar && gorkgall                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:30:40 by smilitar          #+#    #+#             */
/*   Updated: 2026/04/27 16:32:48 by smilitar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *a)
{
	t_node	*current;
	t_node	*next;

	if (!a)
		return ;
	current = a->top;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(a);
}

void	ft_error(t_stack *a)
{
	write(2, "Error\n", 6);
	free_stack(a);
	exit(1);
}