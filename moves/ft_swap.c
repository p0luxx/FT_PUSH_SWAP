#include "../push_swap.h"
 
void	op_sa(t_stack **a, char *ops, int *count)
{
	t_stack	*first;
	t_stack	*second;
 
	if (!a || !(*a) || !(*a)->next)
		return ;
	first = *a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*a = second;
	record_operation(ops, count, "sa");
}
 
void	op_sb(t_stack **b, char *ops, int *count)
{
	t_stack	*first;
	t_stack	*second;
 
	if (!b || !(*b) || !(*b)->next)
		return ;
	first = *b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*b = second;
	record_operation(ops, count, "sb");
}
 
void	op_ss(t_stack **a, t_stack **b, char *ops, int *count)
{
	op_sa(a, ops, count);
	op_sb(b, ops, count);
	/* Remove last two operations and replace with ss */
	if (*count >= 2)
	{
		*count -= 2;
		record_operation(ops, count, "ss");
	}
}
