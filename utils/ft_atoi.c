/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorkgall <gorkgall@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 13:03:49 by gorkgall          #+#    #+#             */
/*   Updated: 2026/05/02 13:16:29 by gorkgall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *s)
{
	long long	res;
	int			i;
	int			np;

	if (!s)
		return (0);
	i = 0;
	res = 0;
	np = 1;
	while (((s[i] >= 8 && s[i] <= 13)) || (s[i] == 32))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			np = -1;
		i++;
	}
	while (ft_is_num(s[i]))
	{
		res *= 10;
		res += s[i] - '0';
		i++;
	}
	return ((int)res * np);
}
