/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smilitar <smilitar@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 15:10:01 by smilitar          #+#    #+#             */
/*   Updated: 2026/04/20 15:17:46 by smilitar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned long n, char *base)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += ft_print_hex(n / 16, base);
	ft_putchar_fd(base[n % 16], 1);
	len++;
	return (len);
}
