/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_simple.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorkgall <gorkgall@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 13:13:02 by gorkgall          #+#    #+#             */
/*   Updated: 2026/05/12 14:18:24 by gorkgall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	find_min_pos(t_node *stack)
{
	t_node	*current;
	int		pos;
	int		min_pos;
	int		min_val;

	if (!stack)
		return (-1);
	current = stack;
	pos = 0;
	min_pos = 0;
	min_val = stack->value;
	while (current)
	{
		if (current->value < min_val)
		{
			min_val = current->value;
			min_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (min_pos);
}

static void	rotate_to_top(t_stack **a, t_count *c, t_bench *bench)
{
	int	pos;
	int	size;
	int	up;
	int	down;
	int	i;

	pos = find_min_pos((*a)->top);
	if (pos <= 0)
		return ;
	size = (*a)->size;
	up = pos;
	down = size - pos;
	i = 0;
	if (up <= down)
		while (i++ < up)
			op_ra(a, c, bench);
	else
		while (i++ < down)
			op_rra(a, c, bench);
}

static void	push_all_to_b(t_stack **a, t_stack **b, t_count *c, t_bench *bench)
{
	while ((*a) && (*a)->size > 1)
	{
		rotate_to_top(a, c, bench);
		op_pb(a, b, c, bench);
	}
}

void	ft_sort_simple(t_stack **a, t_bench *bench)
{
	t_stack	*b;
	t_count	count;

	if (!a || !(*a) || (*a)->size <= 1)
		return ;
	count.ops = malloc(sizeof(char) * 10000);
	if (!count.ops)
		return ;
	count.ops[0] = '\0';
	count.op_count = 0;
	b = ft_init_stack('b');
	if (!b)
	{
		free(count.ops);
		return ;
	}
	push_all_to_b(a, &b, &count, bench);
	while (b && b->size > 0)
		op_pa(a, &b, &count, bench);
	free_stack(b);
	bench->total_ops = count.op_count;
	print_ops(count.ops, count.op_count);
	free(count.ops);
}
