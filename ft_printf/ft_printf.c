/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smilitar <smilitar@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 23:32:41 by smilitar          #+#    #+#             */
/*   Updated: 2026/04/17 00:08:21 by smilitar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"

static int	handle_conversion(char type, va_list args)
{
	if (type == 'c')
		return (ft_print_char(va_arg(args, int)));
	if (type == 's')
		return (ft_print_str(va_arg(args, char *)));
	if (type == 'd' || type == 'i')
		return (ft_print_int(va_arg(args, int)));
	if (type == 'u')
		return (ft_print_un_int(va_arg(args, unsigned int)));
	if (type == 'p')
		return (ft_print_ptr(va_arg(args, void *)));
	if (type == 'x')
		return (ft_print_hex(va_arg(args, unsigned int), "0123456789abcdef"));
	if (type == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), "0123456789ABCDEF"));
	if (type == '%')
		return (ft_print_char('%'));
	return (0);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		i;
	int		total;

	i = 0;
	total = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			total += handle_conversion(format[i], args);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			total++;
		}
		i++;
	}
	va_end(args);
	return (total);
}
