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

void	op_ra(t_stack **a, t_count *c, t_bench *bench)
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
	record_operation(c->ops, &c->op_count, "ra");
	bench->ra++;
}

void	op_rb(t_stack **b, t_count *c, t_bench *bench)
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
	record_operation(c->ops, &c->op_count, "rb");
	bench->rb++;
}

void	op_rr(t_stack **a, t_stack **b, t_count *c, t_bench *bench)
{
	t_node	*first_a;
	t_node	*first_b;

	if (!a || !(*a) || (*a)->size < 2 || !b || !(*b) || (*b)->size < 2)
		return ;
	first_a = (*a)->top;
	(*a)->top = first_a->next;
	if ((*a)->top)
		(*a)->top->prev = NULL;
	(*a)->bottom->next = first_a;
	first_a->prev = (*a)->bottom;
	first_a->next = NULL;
	(*a)->bottom = first_a;
	first_b = (*b)->top;
	(*b)->top = first_b->next;
	if ((*b)->top)
		(*b)->top->prev = NULL;
	(*b)->bottom->next = first_b;
	first_b->prev = (*b)->bottom;
	first_b->next = NULL;
	(*b)->bottom = first_b;
	record_operation(c->ops, &c->op_count, "rr");
	bench->rr++;
}
