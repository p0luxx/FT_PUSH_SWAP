/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorkgall <gorkgall@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 11:37:33 by gorkgall          #+#    #+#             */
/*   Updated: 2026/04/24 14:13:33 by gorkgall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "push_swap.c"
#include <stddef.h>
#include <stdlib.h>
int	ft_check_argv(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if ((s[i] >= '0' && s[i] <= '9'))
			i++;
		else if (s[i] == '-' || s[i] == '+' || s[i] == 32)
			i++;
		else
			return (0);
	}
	return (1);
}
/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	printf("%d\n", ft_check_argv(argv[1]));
	return (0);
}*/
