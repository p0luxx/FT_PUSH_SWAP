#include "../push_swap.h"

void	record_operation(char *ops, int *count, const char *op)
{
	int	i;
 
	if (!ops || !op || *count < 0)
		return ;
	i = 0;
	while (ops[*count * 10 + i] && i < 10)
		i++;
	if (i + strlen(op) < 10)
	{
		strcpy(&ops[*count * 10], op);
		(*count)++;
	}
}
