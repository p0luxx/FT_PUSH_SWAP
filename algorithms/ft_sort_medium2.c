#include "../push_swap.h"

void	push_chunks_to_b(t_stack **a, t_stack **b, int cs, char *ops, int *c)
{
	int	total;
	int	chunk_max;

	total = (*a)->size;
	chunk_max = cs;
	while ((*a)->size > 0)
	{
		if (get_index((*a)->top, (*a)->top->value) < chunk_max)
		{
			op_pb(a, b, ops, c);
			if ((*b)->size > 1 && (*b)->top->value < (*b)->top->next->value)
				op_rb(b, ops, c);
		}
		else
			op_ra(a, ops, c);
		if (chunk_max - (total - (*a)->size) < 1)
			chunk_max += cs;
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
	char	ops[10000];
	int		op_count;

	if (!a || !(*a) || (*a)->size <= 1)
		return ;
	b = NULL;
	op_count = 0;
	chunk_size = ft_sqrt((*a)->size);
	if (chunk_size < 2)
		chunk_size = 2;
	push_chunks_to_b(a, &b, chunk_size, ops, &op_count);
	push_back_to_a(a, &b, ops, &op_count);
}