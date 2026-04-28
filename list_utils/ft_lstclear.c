/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorkgall <gorkgall@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 10:59:00 by gorkgall          #+#    #+#             */
/*   Updated: 2026/04/28 12:07:10 by gorkgall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_lstclear(t_node **lst, void (*del)(void *))
{
	t_node	*aux;

	if (!lst || !del || !*lst)
		return ;
	while (*lst)
	{
		aux = (*lst)-> next;
		ft_lstdelone(*lst, del);
		*lst = aux;
	}
}
