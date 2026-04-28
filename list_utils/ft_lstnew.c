/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorkgall <gorkgall@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 14:41:41 by gorkgall          #+#    #+#             */
/*   Updated: 2026/04/15 15:22:31 by gorkgall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_list;

	new_list = malloc(sizeof(t_list));
	if (!new_list)
		return (NULL);
	new_list -> content = content;
	new_list -> next = NULL;
	return (new_list);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*str = "Hello world :)";
	t_list	*res = ft_lstnew(str);
	if (!res)
		printf("El puntero devuelto es NULL -> Error de memoria");
	else if (res)
		printf("El puntero devuelro es correcto: %s\n", (char *)res -> content);
	if (res -> next == NULL)
		printf("Test next: OK");
	else if (!res -> next)
		printf("Test next: K.O");
	free(res);
	return (0);
}*/
