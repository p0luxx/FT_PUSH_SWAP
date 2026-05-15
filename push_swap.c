/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smilitar && gorkgall                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 15:30:54 by smilitar          #+#    #+#             */
/*   Updated: 2026/05/12 13:51:08 by gorkgall         ###   ########.fr       */
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
void	ft_print_disorder(double disorder)
{
	int	integer;
	int	decimal;

	integer = (int)(disorder * 100);
	decimal = (int)((disorder - integer));
	if (decimal < 0)
		decimal = -decimal;
	ft_putstr_fd("[bench] disorder:   ", 2);
	ft_putnbr_fd(integer, 2);
	ft_putchar_fd('.', 2);
	ft_putnbr_fd(decimal, 2);
	ft_putendl_fd("%", 2);
}

void	ft_print_bench(t_bench *bench)
{
	ft_print_disorder(bench->disorder);
	ft_putstr_fd("[bench] strategy:   ", 2);
	ft_putendl_fd(bench->strategy, 2);
	ft_putstr_fd("[bench] total_ops:  ",2);
	ft_putnbr_fd(bench->total_ops, 2);
	ft_putendl_fd("", 2);
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(bench->sa, 2);
	ft_putstr_fd("  sb: ", 2);
	ft_putendl_fd("", 2);
	/*ft_printf("[bench] sa: %d  sb: %d  ss: %d  pa: %d  pb: %d\n",
		bench->sa, bench->sb, bench->ss, bench->pa, bench->pb);
	ft_printf("[bench] ra: %d  rb: %d  rr: %d  rra: %d  rrb: %d  rrr: %d\n",
		bench->ra, bench->rb, bench->rr, bench->rra, bench->rrb, bench->rrr);*/
}

void	ft_sort(t_flags *f, t_stack **a, t_bench bench)
{
	if (ft_is_sorted(*a) == 0)
	{
		if (f->simple)
		ft_sort_simple(a);
	else if (f->medium)
		ft_sort_medium(a);
	else if (f->complex)
		ft_sort_complex(a);
	else
		ft_sort_adaptive(a, &bench);
	}
}

int	main(int argc, char **argv)
{
	t_flags	f;
	t_stack	*a;
	t_bench bench;

	a = ft_init_stack('a');
	if (!a)
		ft_error(a);
	ft_init_flags(&f);
	ft_parse_argv(argc, argv, &f, &a);
	ft_init_bench(&bench, a, &f);
	if (f.bench)
    	ft_print_bench(&bench);
	ft_sort(&f, &a, bench);
	//print_flags(&f);
	free_stack(a);
	return (0);
}

/*
 algoritmos
--simple    Sort	 	 				O(n²)      fácil de implementar
--medium    Chunk						O(n√n)     reutiliza mirror
--complex   Radix						O(n log n) garantiza excelente
--adaptive  disorder < 0.2 → simple
            disorder < 0.5 → medium
            disorder ≥ 0.5 → complex
            */
