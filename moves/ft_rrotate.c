/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smilitar && gorkgall                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 01:08:12 by smilitar          #+#    #+#             */
/*   Updated: 2026/05/12 13:11:32 by gorkgall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	op_rra(t_stack **a, char *ops, int *count)
{
	t_node	*last;

	if (!a || !(*a) || (*a)->size < 2)
		return ;
	last = (*a)->bottom;
	(*a)->bottom = last->prev;
	if ((*a)->bottom)
		(*a)->bottom->next = NULL;
	last->prev = NULL;
	last->next = (*a)->top;
	if ((*a)->top)
		(*a)->top->prev = last;
	(*a)->top = last;
	record_operation(ops, count, "rra");
}

void	op_rrb(t_stack **b, char *ops, int *count)
{
	t_node	*last;

	if (!b || !(*b) || (*b)->size < 2)
		return ;
	last = (*b)->bottom;
	(*b)->bottom = last->prev;
	if ((*b)->bottom)
		(*b)->bottom->next = NULL;
	last->prev = NULL;
	last->next = (*b)->top;
	if ((*b)->top)
		(*b)->top->prev = last;
	(*b)->top = last;
	record_operation(ops, count, "rrb");
}

void	op_rrr(t_stack **a, t_stack **b, char *ops, int *count)
{
	op_rra(a, ops, count);
	op_rrb(b, ops, count);
	if (*count >= 2)
	{
		*count -= 2;
		record_operation(ops, count, "rrr");
	}
}
