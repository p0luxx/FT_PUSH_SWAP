/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorkgall <gorkgall@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 14:41:41 by gorkgall          #+#    #+#             */
/*   Updated: 2026/04/28 12:16:47 by gorkgall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_node	*ft_lstnew(int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node -> value = value;
	new_node -> norm = 0;
	new_node -> target = 0;
	new_node -> cost_a = 0;
	new_node -> cost_b = 0;
	new_node -> prev = NULL;
	new_node -> next = NULL;
	return (new_node);
}
