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

void	op_rra(t_stack **a, t_count *c, t_bench *bench)
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
	record_operation(c->ops, &c->op_count, "rra");
	bench->rra++;
}

void	op_rrb(t_stack **b, t_count *c, t_bench *bench)
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
	record_operation(c->ops, &c->op_count, "rrb");
	bench->rrb++;
}

void	op_rrr(t_stack **a, t_stack **b, t_count *c, t_bench *bench)
{
	op_rra(a, c, bench);
	op_rrb(b, c, bench);
	if (c->op_count >= 2)
	{
		c->op_count -= 2;
		bench->rra--;
		bench->rrb--;
		record_operation(c->ops, &c->op_count, "rrr");
		bench->rrr++;
	}
}
