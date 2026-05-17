/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_complex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorkgall <gorkgall@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 22:20:04 by smilitar          #+#    #+#             */
/*   Updated: 2026/05/17 15:56:31 by polux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	process_bit(t_stack **a, t_stack **b, int bit, t_count *c)
{
	int	size;
	int	i;

	size = (*a)->size;
	i = 0;
	while (i < size)
	{
		if ((((*a)->top->value >> bit) & 1) == 0)
			op_pb(a, b, c, c->bench);
		else
			op_ra(a, c, c->bench);
		i++;
	}
	while ((*b)->size > 0)
		op_pa(a, b, c, c->bench);
}

static int	init_complex(t_count *count, t_stack **b, t_bench *bench)
{
	count->ops = malloc(sizeof(char) * 50000);
	if (!count->ops)
		return (0);
	count->ops[0] = '\0';
	count->op_count = 0;
	count->bench = bench;
	*b = ft_init_stack('b');
	if (!(*b))
	{
		free(count->ops);
		return (0);
	}
	return (1);
}

void	ft_sort_complex(t_stack **a, t_bench *bench)
{
	t_stack	*b;
	t_count	count;
	int		bits;
	int		i;

	if (!a || !(*a) || (*a)->size <= 1)
		return ;
	if (!init_complex(&count, &b, bench))
		return ;
	if ((*a)->size <= 5)
		return (ft_sort_small(a, bench));
	normalize_stack(a);
	bits = get_max_bits(get_max_value((*a)->top));
	i = 0;
	while (i < bits)
	{
		process_bit(a, &b, i, &count);
		i++;
	}
	bench->total_ops = count.op_count;
	free(b);
	print_ops(count.ops, count.op_count);
	free(count.ops);
}
