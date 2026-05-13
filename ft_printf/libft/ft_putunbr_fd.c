/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smilitar <smilitar@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 12:14:03 by smilitar          #+#    #+#             */
/*   Updated: 2026/04/20 12:14:23 by smilitar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_nb(unsigned int n)
{
	int	len;

	len = 1;
	while (n > 9)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static void	ft_iterative(char *str, unsigned int n, int i)
{
	str[i] = (n % 10) + '0';
	if (n > 9)
	{
		n = n / 10;
		i--;
		ft_iterative(str, n, i);
	}
}

void	ft_putunbr_fd(unsigned int n, int fd)
{
	char	str[12];

	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	ft_iterative(str, n, len_nb(n) - 1);
	str[len_nb(n)] = '\0';
	write(fd, str, len_nb(n));
}
