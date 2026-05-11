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

/*static void	print_flags(t_flags *f)
{
	printf("=== FLAGS ===\n");
	printf("simple:   %d\n", f->simple);
	printf("medium:   %d\n", f->medium);
	printf("complex:  %d\n", f->complex);
	printf("adaptive: %d\n", f->adaptive);
	printf("bench:    %d\n", f->bench);
	printf("=============\n");
}*/

/*void	ft_sort(t_flags *f, t_stack **a)
{
	if (f->simple)
		ft_sort_simple(a);
	else if (f->medium)
		ft_sort_medium(a);
	else if (f->complex)
		ft_sort_complex(a);
	else
		ft_sort_adaptive(a);
}*/

int	main(int argc, char **argv)
{
	t_flags	f;
	t_stack	*a;

	a = ft_init_stack('a');
	if (!a)
		ft_error(a);
	ft_init_flags(&f);
	ft_parse_argv(argc, argv, &f, &a);
	//ft_sort(&f, &a);
	//print_flags(&f);
	free_stack(a);
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
