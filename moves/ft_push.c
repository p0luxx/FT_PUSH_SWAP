#include "../push_swap.h"

void	op_pa(t_stack **a, t_stack **b, char *ops, int *count)
{
	t_stack	*temp;
 
	if (!b || !(*b))
		return ;
	temp = stack_pop(b);
	stack_add_front(a, temp);
	record_operation(ops, count, "pa");
}
 
void	op_pb(t_stack **a, t_stack **b, char *ops, int *count)
{
	t_stack	*temp;
 
	if (!a || !(*a))
		return ;
	temp = stack_pop(a);
	stack_add_front(b, temp);
	record_operation(ops, count, "pb");
}

