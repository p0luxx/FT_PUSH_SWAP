/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_medium.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorkgall <gorkgall@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 22:19:49 by smilitar          #+#    #+#             */
/*   Updated: 2026/05/14 10:48:37 by gorkgall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_index(t_node *stack, int value)
{
	t_node	*current;
	int		index;

	index = 0;
	current = stack;
	while (current)
	{
		if (current->value < value)
			index++;
		current = current->next;
	}
	return (index);
}

int	find_max(t_node *stack)
{
	t_node	*current;
	int		max;

	if (!stack)
		return (0);
	current = stack;
	max = stack->value;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

int	find_position(t_node *stack, int value)
{
	t_node	*current;
	int		pos;

	current = stack;
	pos = 0;
	while (current)
	{
		if (current->value == value)
			return (pos);
		current = current->next;
		pos++;
	}
	return (-1);
}

void	rotate_val_to_top_a(t_stack **s, int val, t_count *c, t_bench *bench)
{
	int	pos;
	int	size;
	int	i;

	pos = find_position((*s)->top, val);
	if (pos < 0)
		return ;
	size = (*s)->size;
	i = -1;
	if (pos <= size / 2)
		while (++i < pos)
			op_ra(s, c, bench);
	else
		while (++i < size - pos)
			op_rra(s, c, bench);
}

void	rotate_val_to_top_b(t_stack **s, int val, t_count *c, t_bench *bench)
{
	int	pos;
	int	size;
	int	i;

	pos = find_position((*s)->top, val);
	if (pos < 0)
		return ;
	size = (*s)->size;
	i = -1;
	if (pos <= size / 2)
		while (++i < pos)
			op_rb(s, c, bench);
	else
		while (++i < size - pos)
			op_rrb(s, c, bench);
}
