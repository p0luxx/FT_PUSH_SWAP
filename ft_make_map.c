/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorkgall <gorkgall@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 00:15:18 by gorkgall          #+#    #+#             */
/*   Updated: 2026/04/30 21:49:53 by gorkgall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// esta funcion sera la encargada de crear la lista enlazada usando un array de enteros.

static	void	ft_lstdelon_map(t_node *lst)
{
	if (!lst)
		return ;
	free(lst);
}

static	void	ft_lstclear_map(t_node **lst)
{
	t_node	*aux;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		aux = (*lst)-> next;
		ft_lstdelone_map(*lst);
		*lst = aux;
	}
}

void	ft_make_map(int *arr, t_node **list, size_t size)
{
	//mientras recorremos, llamaremos a ft_lstnew para ir creando cada nodo con los valores correctos

	size_t	i;
	t_node	*node;

	i = 0;
	if (!arr || !list)
		return ;
	while(i < size)
	{
		node = ft_lstnew(arr[i]);
		if (!node)
		{
			ft_lstclear_map(list)
			return ;
		}
		ft_lstadd_back(list, node);
		i++;
	}
}