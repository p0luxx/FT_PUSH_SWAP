/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smilitar <smilitar@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 21:40:32 by smilitar          #+#    #+#             */
/*   Updated: 2026/04/13 22:02:46 by smilitar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t siz)
{
	size_t	len;
	size_t	copy_len;

	len = ft_strlen(src);
	if (siz == 0)
		return (len);
	if (len >= siz)
		copy_len = siz - 1;
	else
		copy_len = len;
	ft_memcpy(dest, src, copy_len);
	dest[copy_len] = '\0';
	return (len);
}
