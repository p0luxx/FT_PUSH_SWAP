/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_simple.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smilitar <smilitar@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 22:19:30 by smilitar          #+#    #+#             */
/*   Updated: 2026/05/12 08:47:11 by polux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_simple.c - INSERTION SORT O(n²)           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorkgall <gorkgall@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Updated: 2026/05/12 06:45:00 by gorkgall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Encuentra la posición del mínimo en el stack
 */
static int	find_min_pos(t_stack *stack)
{
	t_stack	*current;
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

/**
 * Rota el mínimo a la cima (elige el camino más corto)
 */
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
	if (up <= down)
	{
		i = 0;
		while (i < up)
		{
			op_ra(a, ops, count);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < down)
		{
			op_rra(a, ops, count);
			i++;
		}
	}
}

/**
 * INSERTION SORT O(n²)
 *
 * 1. Encontrar mínimo en A
 * 2. Rotarlo a la cima
 * 3. Empujarlo a B
 * 4. Repetir hasta que A tenga 1 elemento
 * 5. Devolver de B a A
 */
void	ft_sort_simple(t_stack **a)
{
	t_stack	*b;
	int		min_pos;
	int		size_a;
	char	ops[10000];
	int		op_count;

	if (!a || !(*a) || ft_lstsize(*a) <= 1)
		return ;
	b = NULL;
	op_count = 0;
	while ((*a) && (*a)->next)
	{
		size_a = ft_lstsize(*a);
		min_pos = find_min_pos(*a);
		if (min_pos < 0)
			break ;
		rotate_to_top(a, min_pos, size_a, ops, &op_count);
		op_pb(a, &b, ops, &op_count);
	}
	while (b)
		op_pa(a, &b, ops, &op_count);
}
