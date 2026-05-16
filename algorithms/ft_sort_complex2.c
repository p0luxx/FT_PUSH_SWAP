/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_complex2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smilitar <smilitar@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 13:31:04 by smilitar          #+#    #+#             */
/*   Updated: 2026/05/16 13:31:06 by smilitar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	assign_indexes(t_node *current, int *original, int size)
{
	int	index;
	int	i;
	int	j;

	i = 0;
	while (current)
	{
		index = 0;
		j = 0;
		while (j < size)
		{
			if (original[j] < original[i])
				index++;
			j++;
		}
		current->value = index;
		current = current->next;
		i++;
	}
}

void	normalize_stack(t_stack **stack)
{
	t_node	*current;
	int		*original;
	int		i;

	i = 0;
	current = (*stack)->top;
	original = malloc(sizeof(int) * (*stack)->size);
	while (current)
	{
		original[i++] = current->value;
		current = current->next;
	}
	assign_indexes((*stack)->top, original, (*stack)->size);
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
