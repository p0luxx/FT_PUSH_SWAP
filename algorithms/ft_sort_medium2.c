/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_medium2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polux <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 18:15:39 by polux             #+#    #+#             */
/*   Updated: 2026/05/15 18:20:02 by polux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

/* Declaramos la función que ya tienes en ft_sort_complex.c */
void	normalize_stack(t_stack **stack);

static int	ft_optimal_chunk_size(int n)
{
	if (n <= 20)
		return (n);
	if (n <= 50)
		return (8);
	if (n <= 100)
		return (14);
	if (n <= 200)
		return (22);
	if (n <= 500)
		return (38);
	return (45);
}

static int	should_sink_in_b(int elem_global_idx, int chunk_min, int cs)
{
	return (elem_global_idx - chunk_min < cs / 2);
}

void	push_chunks_to_b(t_stack **a, t_stack **b, int cs, char *ops, int *c)
{
	int	total;
	int	chunk_min;
	int	chunk_max;
	int	elem_global_idx;

	total = (*a)->size;
	chunk_min = 0;
	chunk_max = cs;
	while ((*a)->size > 0)
	{
		/* Ahora usamos el valor normalizado, que es seguro y no cambia */
		elem_global_idx = (*a)->top->value;
		if (elem_global_idx >= chunk_min && elem_global_idx < chunk_max)
		{
			op_pb(a, b, ops, c);
			if ((*b)->size > 1
				&& should_sink_in_b(elem_global_idx, chunk_min, cs))
				op_rb(b, ops, c);
			if (chunk_max - (total - (*a)->size) < 1)
			{
				chunk_min = chunk_max;
				chunk_max += cs;
			}
		}
		else
			op_ra(a, ops, c);
	}
}

void	push_back_to_a(t_stack **a, t_stack **b, char *ops, int *count)
{
	int	max;

	while ((*b)->size > 0)
	{
		max = find_max((*b)->top);
		rotate_value_to_top(b, max, 'b', ops, count);
		op_pa(a, b, ops, count);
	}
}

void	ft_sort_medium(t_stack **a)
{
	t_stack	*b;
	int		chunk_size;
	char	*ops;
	int		op_count;

	if (!a || !(*a) || (*a)->size <= 1)
		return ;
	b = ft_init_stack('b');
	if (!b)
		return ;
	/* Asignación segura en el Heap */
	ops = malloc(2000000);
	if (!ops)
	{
		free(b);
		return ;
	}
	op_count = 0;
	ops[0] = '\0';
	
	normalize_stack(a); /* ESTO EVITA EL BUCLE INFINITO */
	chunk_size = ft_optimal_chunk_size((*a)->size);
	push_chunks_to_b(a, &b, chunk_size, ops, &op_count);
	push_back_to_a(a, &b, ops, &op_count);
	
	free(b);
	print_ops(ops, op_count);
	free(ops);
}
