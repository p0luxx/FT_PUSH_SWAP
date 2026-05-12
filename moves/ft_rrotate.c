#include "../push_swap.h"

void	op_rra(t_stack **a, char *ops, int *count)
{
	t_stack	*last;
	t_stack	*current;
 
	if (!a || !(*a) || !(*a)->next)
		return ;
	current = *a;
	while (current->next->next)
		current = current->next;
	last = current->next;
	current->next = NULL;
	stack_add_front(a, last);
	record_operation(ops, count, "rra");
}
 
void	op_rrb(t_stack **b, char *ops, int *count)
{
	t_stack	*last;
	t_stack	*current;
 
	if (!b || !(*b) || !(*b)->next)
		return ;
	current = *b;
	while (current->next->next)
		current = current->next;
	last = current->next;
	current->next = NULL;
	stack_add_front(b, last);
	record_operation(ops, count, "rrb");
}
 
void	op_rrr(t_stack **a, t_stack **b, char *ops, int *count)
{
	op_rra(a, ops, count);
	op_rrb(b, ops, count);
	/* Remove last two operations and replace with rrr */
	if (*count >= 2)
	{
		*count -= 2;
		record_operation(ops, count, "rrr");
	}
}

