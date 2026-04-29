/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorkgall <gorkgall@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 15:43:17 by gorkgall          #+#    #+#             */
/*   Updated: 2026/04/28 12:06:33 by gorkgall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_lstadd_front(t_node **lst, t_node *node)
{
	if (!lst || !node)
		return ;
	node -> next = *lst;
	*lst -> prev = node;
	node -> prev = NULL;
	*lst = node;
}
