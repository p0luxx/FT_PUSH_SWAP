/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_adaptative.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smilitar <smilitar@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 22:20:21 by smilitar          #+#    #+#             */
/*   Updated: 2026/05/17 15:56:02 by polux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_adaptive(t_stack **a, t_bench *bench)
{
	if (bench->disorder < 0.2)
		ft_sort_simple(a, bench);
	else if (bench->disorder >= 0.2 && bench->disorder < 0.5)
		ft_sort_medium(a, bench);
	else
		ft_sort_complex(a, bench);
}
