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

int	ft_sqrt(int n)
{
	int	i;

	if (n <= 0)
		return (0);
	i = 1;
	while (i * i < n)
		i++;
	if (i * i > n)
		i--;
	return (i);
}

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

void	rotate_value_to_top(t_stack **s, int val, char n, char *ops, int *c)
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
			(n == 'a') ? op_ra(s, ops, c) : op_rb(s, ops, c);
	else
		while (++i < size - pos)
			(n == 'a') ? op_rra(s, ops, c) : op_rrb(s, ops, c);
}