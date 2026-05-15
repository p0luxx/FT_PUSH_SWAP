#include "../push_swap.h"

int	is_sorted(t_stack *a)
{
	t_node	*cur;

	cur = a->top;
	while (cur && cur->next)
	{
		if (cur->value > cur->next->value)
			return (0);
		cur = cur->next;
	}
	return (1);
}