/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smilitar && gorkgall                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 01:07:55 by smilitar          #+#    #+#             */
/*   Updated: 2026/05/12 13:10:41 by gorkgall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

void	op_pa(t_stack **a, t_stack **b, char *ops, int *count)
{
	t_node	*temp;

	if (!b || !(*b) || !a || !(*a))
		return ;
	temp = (*b)->top;
	(*b)->top = (*b)->top->next;
	if ((*b)->top)
		(*b)->top->prev = NULL;
	else
		(*b)->bottom = NULL;
	(*b)->size--;
	temp->next = (*a)->top;
	temp->prev = NULL;
	if ((*a)->top)
		(*a)->top->prev = temp;
	else
		(*a)->bottom = temp;
	(*a)->top = temp;
	(*a)->size++;
	record_operation(ops, count, "pa");
}

void	op_pb(t_stack **a, t_stack **b, char *ops, int *count)
{
	t_node	*temp;

	if (!a || !(*a) || !b || !(*b))
		return ;
	temp = (*a)->top;
	(*a)->top = (*a)->top->next;
	if ((*a)->top)
		(*a)->top->prev = NULL;
	else
		(*a)->bottom = NULL;
	(*a)->size--;
	temp->next = (*b)->top;
	temp->prev = NULL;
	if ((*b)->top)
		(*b)->top->prev = temp;
	else
		(*b)->bottom = temp;
	(*b)->top = temp;
	(*b)->size++;
	record_operation(ops, count, "pb");
}
