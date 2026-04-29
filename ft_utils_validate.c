/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_validate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smilitar <smilitar@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 20:20:36 by smilitar          #+#    #+#             */
/*   Updated: 2026/04/27 20:20:41 by smilitar         ###   ########.fr       */
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

int	ft_check_argv(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		while (s[i] == 32)
			i++;
		if (!s[i])
			break ;
		if (s[i] == '-' || s[i] == '+')
			i++;
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (0);
		while (s[i] >= '0' && s[i] <= '9')
			i++;
		if (s[i] != 32 && s[i] != '\0')
			return (0);
	}
	return (1);
}

int	ft_is_num(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == 32)
			return (0);
		i++;
	}
	
	return (1);
}

int	ft_is_repeat_val(int *matriz, int size)
{
	int	i;
	int	j;
	i = 0;
	j = 0;
	while (matrix[i])
	{
		j = i + 1;
		while(matrix[j])
		{
			if (matrix[i] == matrix[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
