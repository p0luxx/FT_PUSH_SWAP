#include "../push_swap.h"

static int	get_min_pos(t_node *stack)
{
	t_node	*current;
	int		pos;
	int		min_pos;
	int		min_val;

	pos = 0;
	min_pos = 0;
	min_val = stack->value;
	current = stack;
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

static void	sort_three(t_stack **a, t_count *c, t_bench *bench)
{
	int	top;
	int	mid;
	int	bot;

	top = (*a)->top->value;
	mid = (*a)->top->next->value;
	bot = (*a)->top->next->next->value;
	if (top > mid && top > bot)
		op_ra(a, c, bench);
	else if (mid > top && mid > bot)
		op_rra(a, c, bench);
	if ((*a)->top->value > (*a)->top->next->value)
		op_sa(a, c, bench);
}

static void	push_min_to_b(t_stack **a, t_stack **b, t_count *c, t_bench *bch)
{
	int	min_pos;

	while ((*a)->size > 3)
	{
		min_pos = get_min_pos((*a)->top);
		if (min_pos <= (*a)->size / 2)
			while (min_pos-- > 0)
				op_ra(a, c, bch);
		else
			while (min_pos++ < (*a)->size)
				op_rra(a, c, bch);
		op_pb(a, b, c, bch);
	}
}

static int	sort_four_five(t_stack **a, t_count *c, t_bench *bench)
{
	t_stack	*b;

	b = ft_init_stack('b');
	if (!b)
		return (0);
	push_min_to_b(a, &b, c, bench);
	sort_three(a, c, bench);
	while (b && b->size > 0)
		op_pa(a, &b, c, bench);
	free_stack(b);
	return (1);
}

void	ft_sort_small(t_stack **a, t_bench *bench)
{
	t_count	count;

	if (!a || !(*a) || (*a)->size <= 1)
		return ;
	count.ops = malloc(sizeof(char) * 10000);
	if (!count.ops)
		return ;
	count.ops[0] = '\0';
	count.op_count = 0;
	if ((*a)->size == 2 && (*a)->top->value > (*a)->top->next->value)
		op_sa(a, &count, bench);
	else if ((*a)->size == 3)
		sort_three(a, &count, bench);
	else if ((*a)->size > 3 && !sort_four_five(a, &count, bench))
		return (free(count.ops));
	bench->total_ops = count.op_count;
	print_ops(count.ops, count.op_count);
	free(count.ops);
}
