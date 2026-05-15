/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smilitar && gorkgall                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 01:08:02 by smilitar          #+#    #+#             */
/*   Updated: 2026/05/12 13:11:07 by gorkgall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

void	op_ra(t_stack **a, char *ops, int *count)
{
	t_node	*first;

	if (!a || !(*a) || (*a)->size < 2)
		return ;
	first = (*a)->top;
	(*a)->top = first->next;
	if ((*a)->top)
		(*a)->top->prev = NULL;
	(*a)->bottom->next = first;
	first->prev = (*a)->bottom;
	first->next = NULL;
	(*a)->bottom = first;
	record_operation(ops, count, "ra");
}

void	op_rb(t_stack **b, char *ops, int *count)
{
	t_node	*first;

	if (!b || !(*b) || (*b)->size < 2)
		return ;
	first = (*b)->top;
	(*b)->top = first->next;
	if ((*b)->top)
		(*b)->top->prev = NULL;
	(*b)->bottom->next = first;
	first->prev = (*b)->bottom;
	first->next = NULL;
	(*b)->bottom = first;
	record_operation(ops, count, "rb");
}

void	op_rr(t_stack **a, t_stack **b, char *ops, int *count)
{
	op_ra(a, ops, count);
	op_rb(b, ops, count);
	if (*count >= 2)
	{
		*count -= 2;
		record_operation(ops, count, "rr");
	}
}
