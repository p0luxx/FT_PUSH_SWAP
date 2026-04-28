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

t_node	*ft_lstnew(int *content)
{
	t_node	*new_list;

	new_list = malloc(sizeof(t_node));
	if (!new_list)
		return (NULL);
	new_list -> content = content;
	new_list -> next = NULL;
	return (new_list);
}
