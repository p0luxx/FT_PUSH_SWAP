/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smilitar <smilitar@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 08:49:54 by smilitar          #+#    #+#             */
/*   Updated: 2026/04/17 08:49:57 by smilitar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

int	ft_printf(char const *format, ...);
int	ft_print_char(int c);
int	ft_print_str(char *s);
int	ft_print_int(int d);
int	ft_print_un_int(unsigned int d);
int	ft_print_hex(unsigned long n, char *base);
int	ft_print_ptr(void *ptr);

#endif
