/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorkgall <gorkgall@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 15:43:17 by gorkgall          #+#    #+#             */
/*   Updated: 2026/04/16 09:22:09 by gorkgall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new -> next = *lst;
	*lst = new;
}

/*
t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node || !content)
		return (NULL);
	new_node -> content = content;
	new_node -> next = NULL;
	return (new_node);
}

#include <stdio.h>
int	main(void)
{
	t_list	*head = ft_lstnew("Head");
	if (!head)
		printf("Hubo un error al crear el nodo head");
	t_list	*node_1 = ft_lstnew("Node 1");
	if (!node_1)
		printf("Hubo un error al crear el nodo 1");
	t_list	*node_2 = ft_lstnew("Node 2");
	if (!node_2)
		printf("Hubo un error al crear el nodo 2");
	ft_lstadd_front(&head, node_1);
	ft_lstadd_front(&head, node_2);
	t_list	*temp = head;
	while (temp)
	{
		printf("%s\n", (char *)temp -> content);
		temp = temp -> next;
	}
	return (0);
}*/