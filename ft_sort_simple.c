/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_simple.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smilitar <smilitar@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 22:19:30 by smilitar          #+#    #+#             */
/*   Updated: 2026/05/10 22:19:41 by smilitar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/*
/sort de 3
/sort de 4
/sort de 5
*/

void    ft_sort_simple(t_stack **a)
{
    t_stack *b;

    b = ft_init_stack('b');
    if (!b)
    {
        //free_b()
        ft_error(*a);
    }
    // llamar a las funciones
    free_stack(b);
    (void)a;
}