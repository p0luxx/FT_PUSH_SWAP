/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_complex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorkgall <gorkgall@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 22:20:04 by smilitar          #+#    #+#             */
/*   Updated: 2026/05/15 10:56:16 by polux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	normalize_stack(t_stack **stack)
{
	t_node	*current;
	t_node	*compare;
	int		index;

	current = (*stack)->top;
	while (current)
	{
		index = 0;
		compare = (*stack)->top;
		while (compare)
		{
			if (compare->value < current->value)
				index++;
			compare = compare->next;
		}
		current->value = index;
		current = current->next;
	}
}

int	get_max_value(t_node *stack)
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

int	get_max_bits(int max_num)
{
	int	bits;

	bits = 0;
	while ((max_num >> bits) != 0)
		bits++;
	return (bits);
}

void	process_bit(t_stack **a, t_stack **b, int bit, char *ops, int *c)
{
	int	size;
	int	i;

	size = (*a)->size;
	i = 0;
	while (i < size)
	{
		if ((((*a)->top->value >> bit) & 1) == 1)
			op_pb(a, b, ops, c);
		else
			op_ra(a, ops, c);
		i++;
	}
	while ((*b) && (*b)->size > 0)
		op_pa(a, b, ops, c);
}

void	ft_sort_complex(t_stack **a)
{
	t_stack	*b;
	int		bits;
	int		i;
	char	ops[10000];
	int		op_count;

	if (!a || !(*a) || (*a)->size <= 1)
		return ;
	ops[0] = 0;
	op_count = 0;
	b = ft_init_stack('b');
	if (!b)
		return ;
	normalize_stack(a);
	bits = get_max_bits(get_max_value((*a)->top));
	i = 0;
	while (i < bits)
	{
		process_bit(a, &b, i, ops, &op_count);
		i++;
	}
	free_stack(b);
	print_ops(ops, op_count);
}
