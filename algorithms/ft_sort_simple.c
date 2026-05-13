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

#include "push_swap.h"

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

static void	rotate_to_top(t_stack **a, int pos, int size,
				char *ops, int *count)
{
	int	up;
	int	down;
	int	i;

	if (pos == 0 || pos < 0)
		return ;
	up = pos;
	down = size - pos;
	i = 0;
	if (up <= down)
		while (i++ < up)
			op_ra(a, ops, count);
	else
		while (i++ < down)
			op_rra(a, ops, count);
}

static void	push_all_to_b(t_stack **a, t_stack **b, char *ops, int *count)
{
	int	min_pos;
	int	size_a;

	while ((*a) && (*a)->size > 1)
	{
		size_a = (*a)->size;
		min_pos = find_min_pos((*a)->top);
		if (min_pos < 0)
			break ;
		rotate_to_top(a, min_pos, size_a, ops, count);
		op_pb(a, b, ops, count);
	}
}

void	ft_sort_simple(t_stack **a)
{
	t_stack	*b;
	char	ops[10000];
	int		op_count;

	if (!a || !(*a) || (*a)->size <= 1)
		return ;
	ops[0] = 0;
	op_count = 0;
	b = ft_init_stack('b');
	if (!b)
		return ;
	push_all_to_b(a, &b, ops, &op_count);
	while (b && b->size > 0)
		op_pa(a, &b, ops, &op_count);
	free_stack(b);
	print_ops(ops, op_count);
}
