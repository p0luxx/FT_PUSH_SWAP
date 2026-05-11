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

int	check_sign(char c)
{
	int	np;

	np = 1;
	if (c == '-')
		np = -1;
	return (np);
}

int	ft_atoi(char *s, t_stack **a)
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
		np = check_sign(s[i]);
	if (!ft_is_num(s[i]))
		ft_error(*a);
	while (ft_is_num(s[i]))
	{
		res = res * 10 + s[i] - '0';
		if (res * np > 2147483647LL || res * np < -2147483648LL)
			ft_error(*a);
		i++;
	}
	if (s[i] != '\0')
		ft_error(*a);
	return ((int)res * np);
}
