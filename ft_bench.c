/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_bench.c										 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: smilitar <smilitar@student.42barcelon	  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2026/05/11 16:54:28 by smilitar		  #+#	#+#			 */
/*   Updated: 2026/05/11 16:54:30 by smilitar		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "push_swap.h"

double	ft_calculate_disorder(t_stack *a)
{
	t_node	*i;
	t_node	*j;
	double	mistakes;
	double	total_pairs;

	if (!a || a->size < 2)
		return (0.0);
	mistakes = 0;
	total_pairs = 0;
	i = a->top;
	while (i)
	{
		j = i->next;
		while (j)
		{
			total_pairs++;
			if (i->value > j->value)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	return (mistakes / total_pairs);
}

char	*ft_get_algorithm(t_flags *f, t_bench *bench)
{
	if (f->simple == 1)
		return ("Simple ");
	else if (f->medium == 1)
		return ("Medium");
	else if (f->complex == 1)
		return ("Complex");
	else
	{
		if (bench->disorder < 0.2)
			return ("Adaptive / O(n^2)");
		else if (bench->disorder >= 0.2 && bench->disorder < 0.5)
			return ("Adaptive / O(n√n)");
		else
			return ("Adaptive / O(n log n)");
	}
}

void	ft_init_bench(t_bench *bench, t_stack *a, t_flags *f)
{
	bench->disorder = ft_calculate_disorder(a);
	bench->strategy = ft_get_algorithm(f, bench);
	bench->total_ops = 0;
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
}
