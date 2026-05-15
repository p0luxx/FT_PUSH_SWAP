/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smilitar <smilitar@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 14:14:38 by smilitar          #+#    #+#             */
/*   Updated: 2026/04/16 17:22:02 by smilitar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_nb(int n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 9)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static void	ft_iterative(char *str, int n, int i)
{
	str[i] = (n % 10) + '0';
	if (n > 9)
	{
		n = n / 10;
		i--;
		ft_iterative(str, n, i);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	char	str[12];

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n < 0)
	{
		str[0] = '-';
		ft_iterative(str + 1, -n, len_nb(-n) - 1);
		str[len_nb(n)] = '\0';
		write(fd, str, len_nb(n));
	}
	else
	{
		ft_iterative(str, n, len_nb(n) - 1);
		str[len_nb(n)] = '\0';
		write(fd, str, len_nb(n));
	}
}
