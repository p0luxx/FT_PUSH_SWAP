/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorkgall <gorkgall@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 12:03:31 by gorkgall          #+#    #+#             */
/*   Updated: 2026/04/27 12:48:39 by gorkgall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <unistd.h>
# include <stdint.h>
# include <stddef.h>
# include <stdlib.h>

int	ft_is_num(char	*str);
int	ft_atoi(char *s);
int	*ft_make_matrix(char *str);
int	ft_is_repeat_val(int *matrix);
#endif
