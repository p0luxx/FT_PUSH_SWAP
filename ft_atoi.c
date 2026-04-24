/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorkgall <gorkgall@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 14:09:20 by gorkgall          #+#    #+#             */
/*   Updated: 2026/04/24 15:36:56 by gorkgall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *s)
{
	int	res;
	int	i;
	int	np;

	if (!res)
		return (0);
	i = 0;
	res = 0;
	np = 1;
	while (((s[i] >= 8 && s[i] <= 13)) || (s[i] == 32))
		i++;
	if (s[i++] == '-')
		np = -1;
	while (ft_is_num(s[i]))
	{
		res *= 10;
		res += s[i] - '0';
		i++;
	}
	return (res * np);
}

/*
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	printf("Our atoi -> %d\n", ft_atoi(argv[1]));
	printf("Standard atoi -> %d\n", atoi(argv[1]));
	return (0);
}*/
