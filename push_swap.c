/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smilitar && gorkgall                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 15:30:54 by smilitar          #+#    #+#             */
/*   Updated: 2026/04/27 12:49:49 by gorkgall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	print_flags(t_flags *f)
{
	printf("=== FLAGS ===\n");
	printf("simple:   %d\n", f->simple);
	printf("medium:   %d\n", f->medium);
	printf("complex:  %d\n", f->complex);
	printf("adaptive: %d\n", f->adaptive);
	printf("bench:    %d\n", f->bench);
	printf("=============\n");
}

int	main(int argc, char **argv)
{
	t_flags	f;
	t_stack	*a;

	a = NULL;
	ft_init_flags(&f);
	ft_parse_argv(argc, argv, &f, &a);
	// aqui vienen los siguientes 
	print_flags(&f);
	return (0);
}


/*
 algoritmos
--simple    Insertion expectante     O(n²)      fácil de implementar
--medium    Insertion chunked        O(n√n)     reutiliza mirror
--complex   Radix LSD                O(n log n) garantiza excelente
--adaptive  disorder < 0.1 → simple
            disorder < 0.4 → medium
            disorder ≥ 0.4 → complex
            */
