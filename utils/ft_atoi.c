/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorkgall <gorkgall@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 13:03:49 by gorkgall          #+#    #+#             */
/*   Updated: 2026/05/16 14:20:19 by gorkgall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_atol(char *s, t_stack **a)
{
	long	res;
	int		np;

	res = 0;
	np = 1;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	if (*s == '-' || *s == '+')
		if (*s++ == '-')
			np = -1;
	if (!*s || !ft_is_num(*s))
		ft_error(*a);
	while (*s && ft_is_num(*s))
	{
		res = res * 10 + (*s++ - '0');
		if ((res * np) > 2147483647 || (res * np) < -2147483648)
			ft_error(*a);
	}
	if (*s != '\0')
		ft_error(*a);
	return ((int)(res * np));
}
