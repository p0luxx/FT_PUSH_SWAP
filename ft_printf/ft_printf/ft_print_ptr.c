/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smilitar <smilitar@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 15:40:46 by smilitar          #+#    #+#             */
/*   Updated: 2026/04/20 16:09:51 by smilitar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(void *ptr)
{
	int				len;
	unsigned long	addr;

	if (!ptr)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	len = 0;
	addr = (unsigned long)ptr;
	ft_putstr_fd("0x", 1);
	len = len + 2;
	len += ft_print_hex(addr, "0123456789abcdef");
	return (len);
}
