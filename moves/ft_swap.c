/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smilitar && gorkgall                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 01:08:19 by smilitar          #+#    #+#             */
/*   Updated: 2026/05/12 13:11:48 by gorkgall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

void	op_sa(t_stack **a, char *ops, int *count)
{
	t_node	*first;
	t_node	*second;

	if (!a || !(*a) || (*a)->size < 2)
		return ;
	first = (*a)->top;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	first->prev = second;
	second->prev = NULL;
	(*a)->top = second;
	record_operation(ops, count, "sa");
}

void	op_sb(t_stack **b, char *ops, int *count)
{
	t_node	*first;
	t_node	*second;

	if (!b || !(*b) || (*b)->size < 2)
		return ;
	first = (*b)->top;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	first->prev = second;
	second->prev = NULL;
	(*b)->top = second;
	record_operation(ops, count, "sb");
}

void	op_ss(t_stack **a, t_stack **b, char *ops, int *count)
{
	op_sa(a, ops, count);
	op_sb(b, ops, count);
	if (*count >= 2)
	{
		*count -= 2;
		record_operation(ops, count, "ss");
	}
}
