/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorkgall <gorkgall@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 16:23:40 by gorkgall          #+#    #+#             */
/*   Updated: 2026/05/12 14:10:18 by gorkgall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	record_operation(char *ops, int *count, const char *op)
{
	if (!ops || !op || *count < 0)
		return ;
	ft_strlcpy(&ops[*count * 4], op, 4);
	(*count)++;
}

void	print_ops(char *ops, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		write(1, &ops[i * 4], ft_strlen(&ops[i * 4]));
		write(1, "\n", 1);
		i++;
	}
}
