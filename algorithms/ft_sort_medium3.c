/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_medium3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smilitar <smilitar@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 13:09:40 by smilitar          #+#    #+#             */
/*   Updated: 2026/05/16 13:09:42 by smilitar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_optimal_chunk_size(int n);

static int	should_sink_in_b(int idx, int chunk_min, int cs)
{
	return (idx - chunk_min < cs / 2);
}

void	push_chunks_to_b(t_stack **a, t_stack **b, t_count *c, t_bench *bench)
{
	int	cfg[4];
	int	elem_idx;

	cfg[0] = (*a)->size;
	cfg[1] = ft_optimal_chunk_size(cfg[0]);
	cfg[2] = 0;
	cfg[3] = cfg[1];
	while ((*a)->size > 0)
	{
		elem_idx = (*a)->top->value;
		if (elem_idx >= cfg[2] && elem_idx < cfg[3])
		{
			op_pb(a, b, c, bench);
			if ((*b)->size > 1 && should_sink_in_b(elem_idx, cfg[2], cfg[1]))
				op_rb(b, c, bench);
			if (cfg[3] - (cfg[0] - (*a)->size) < 1)
			{
				cfg[2] = cfg[3];
				cfg[3] += cfg[1];
			}
		}
		else
			op_ra(a, c, bench);
	}
}

void	push_back_to_a(t_stack **a, t_stack **b, t_count *c, t_bench *bench)
{
	int	max;

	while ((*b)->size > 0)
	{
		max = find_max((*b)->top);
		rotate_val_to_top_b(b, max, c, bench);
		op_pa(a, b, c, bench);
	}
}
