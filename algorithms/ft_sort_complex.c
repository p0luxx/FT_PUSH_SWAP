/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_complex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorkgall <gorkgall@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 22:20:04 by smilitar          #+#    #+#             */
/*   Updated: 2026/05/14 10:50:21 by gorkgall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	normalize_stack(t_stack **stack)
{
	t_node	*current;
	int		index;
	int		*original;
	int		i;
	int		j;

	i = 0;
	current = (*stack)->top;
	original = malloc(sizeof(int) * (*stack)->size);
	while (current)
	{
		original[i++] = current->value;
		current = current->next;
	}
	current = (*stack)->top;
	i = 0;
	while (current)
	{
		index = 0;
		j = 0;
		while (j < (*stack)->size)
		{
			if (original[j] < original[i])
				index++;
			j++;
		}
		current->value = index;
		current = current->next;
		i++;
	}
	free(original);
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
		if ((((*a)->top->value >> bit) & 1) == 0)
			op_pb(a, b, ops, c);
		else
			op_ra(a, ops, c);
		i++;
	}
	while ((*b)->size > 0)
		op_pa(a, b, ops, c);
}

void	ft_sort_complex(t_stack **a)
{
	t_stack	*b;
	int		bits;
	int		i;
	char	ops[50000];
	int		op_count;

	if (!a || !(*a) || (*a)->size <= 1)
		return ;
	b = ft_init_stack('b');
	if (!b)
		return ;
	op_count = 0;
	normalize_stack(a);
	bits = get_max_bits(get_max_value((*a)->top));
	i = 0;
	while (i < bits)
	{
		process_bit(a, &b, i, ops, &op_count);
		i++;
	}
	free(b);
	print_ops(ops, op_count);
}