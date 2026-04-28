/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorkgall <gorkgall@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 10:01:32 by gorkgall          #+#    #+#             */
/*   Updated: 2026/04/28 12:05:07 by gorkgall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	ft_lstadd_back(t_node **lst, t_node *new)
{
	t_node	*last_node;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		last_node = ft_lstlast(*lst);
		last_node -> next = new;
	}
}
