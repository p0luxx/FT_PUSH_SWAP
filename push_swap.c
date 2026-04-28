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

void	read_arguments(int argc, char **argv, t_flags *f, t_stack **a)
{
	if (argc < 2 || argc >= 5)
		ft_error(1);
	else if (argc == 2)
	{
		if (ft_is_valid_input(argv[1]))
			*matriz = ft_make_matriz(argv[1]);
		else
			ft_error(1);
	}
	else if (argc == 3)
	{
		ft_select_algorithm(argv[1], f);
		if (ft_is_valid_input(argv[2]))
			*matriz = ft_make_matriz(argv[2]);
		else
			ft_error(1);
	}
	else if (argc == 4)
	{
		ft_validate_single_algorithm(argv[1], argv[2], f);
		if (ft_is_valid_input(argv[3]))
			*matriz = ft_make_matriz(argv[3]);
		else
			ft_error(1);
	}
}

int main(int argc, char **argv)
{
	t_flags f;
	t_stack *a;
	t_stack *b;
	double  disorder;

	ft_init_flags(&f);
	a = ft_new_stack('a');
	b = ft_new_stack('b');

	read_arguments(argc, argv, &f, &a);
	
	/*
	if (ft_is_sorted(a))
	{
		ft_free_stack(a);
		ft_free_stack(b);
		return (0);
	}*/
	/*
	disorder = compute_disorder(a);
	normalize_stack(a);

	if (f.simple)
		sort_simple(a, b);
	else if (f.medium)
		sort_medium(a, b);
	else if (f.complex)
		sort_complex(a, b);
	else
		sort_adaptive(a, b, disorder);
	ft_free_stack(a);
	ft_free_stack(b);*/
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
