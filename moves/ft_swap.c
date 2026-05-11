/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smilitar <smilitar@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 01:08:19 by smilitar          #+#    #+#             */
/*   Updated: 2026/05/11 01:08:20 by smilitar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    ft_sa(t_stack *a)
{
    int tmp;

    if (!a || a->size < 2)
		return ;
    tmp = a->top->value;
    a->top->value = a->top->next->value;
    a->top->next->value = tmp;
}

void    ft_sb(t_stack *b)
{
    int tmp;

    if (!b || b->size < 2)
		return ;
    tmp = b->top->value;
    b->top->value = b->top->next->value;
    b->top->next->value = tmp;
}

void    ft_ss(t_stack *a, t_stack *b)
{
    ft_sa(a);
    ft_sb(b);
}