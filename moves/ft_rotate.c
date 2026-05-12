void	op_ra(t_stack **a, char *ops, int *count)
{
	t_stack	*first;
 
	if (!a || !(*a) || !(*a)->next)
		return ;
	first = stack_pop(a);
	stack_add_back(a, first);
	record_operation(ops, count, "ra");
}
 
void	op_rb(t_stack **b, char *ops, int *count)
{
	t_stack	*first;
 
	if (!b || !(*b) || !(*b)->next)
		return ;
	first = stack_pop(b);
	stack_add_back(b, first);
	record_operation(ops, count, "rb");
}
 
void	op_rr(t_stack **a, t_stack **b, char *ops, int *count)
{
	op_ra(a, ops, count);
	op_rb(b, ops, count);
	/* Remove last two operations and replace with rr */
	if (*count >= 2)
	{
		*count -= 2;
		record_operation(ops, count, "rr");
	}
}
