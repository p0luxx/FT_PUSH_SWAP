/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorkgall <gorkgall@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 14:16:04 by gorkgall          #+#    #+#             */
/*   Updated: 2026/05/02 14:23:21 by gorkgall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (((unsigned char *)s)[i] == ((unsigned char)c))
			return (&((char *)s)[i]);
		i++;
	}
	if (((unsigned char *)s)[i] == ((unsigned char)c))
		return (&((char *)s)[i]);
	return (NULL);
}
