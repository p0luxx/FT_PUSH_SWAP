/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smilitar <smilitar@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 14:06:23 by smilitar          #+#    #+#             */
/*   Updated: 2026/05/09 14:06:58 by smilitar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add_node(t_stack **a, int val, char **tokens)
{
	t_node	*node;

	node = ft_lstnew(val);
	if (!node)
	{
		ft_free_split(tokens);
		ft_error(1);
	}
	ft_lstadd_back(&(*a)->top, node);
	(*a)->size++;
}
