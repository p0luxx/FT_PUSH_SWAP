/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorkgall <gorkgall@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 11:48:58 by gorkgall          #+#    #+#             */
/*   Updated: 2026/04/28 12:09:04 by gorkgall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_node	*ft_lstmap(t_node *lst, void *(*f)(void *), void (*del)(void *))
{
	t_node	*node;
	t_node	*current;
	t_node	*head;

	if (!lst || !f || !del)
		return (NULL);
	node = NULL;
	current = NULL;
	head = NULL;
	while (lst)
	{
		node = ft_lstnew(f(lst -> content));
		if (!node)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		if (!head)
			head = node;
		else
			current -> next = node;
		current = node;
		lst = lst -> next;
	}
	return (head);
}
