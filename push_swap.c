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

void	ft_print_disorder(double disorder)
{
	int	integer;
	int	decimal;

	integer = (int)(disorder * 100);
	decimal = (int)((disorder * 100 - integer) * 10);
	if (decimal < 0)
		decimal = -decimal;
	ft_putstr_fd("[bench] disorder:   ", 2);
	ft_putnbr_fd(integer, 2);
	ft_putchar_fd('.', 2);
	ft_putnbr_fd(decimal, 2);
	ft_putendl_fd("%", 2);
}

static void	ft_print_bench_ops(t_bench *bench)
{
	ft_putstr_fd("[bench] sa:  ", 2);
	ft_putnbr_fd(bench->sa, 2);
	ft_putstr_fd("  sb:  ", 2);
	ft_putnbr_fd(bench->sb, 2);
	ft_putstr_fd("  ss:  ", 2);
	ft_putnbr_fd(bench->ss, 2);
	ft_putstr_fd("  pa:  ", 2);
	ft_putnbr_fd(bench->pa, 2);
	ft_putstr_fd("  pb:  ", 2);
	ft_putnbr_fd(bench->pb, 2);
	ft_putendl_fd("", 2);
	ft_putstr_fd("[bench] ra:  ", 2);
	ft_putnbr_fd(bench->ra, 2);
	ft_putstr_fd("  rb:  ", 2);
	ft_putnbr_fd(bench->rb, 2);
	ft_putstr_fd("  rr:  ", 2);
	ft_putnbr_fd(bench->rr, 2);
	ft_putstr_fd("  rra:  ", 2);
	ft_putnbr_fd(bench->rra, 2);
	ft_putstr_fd("  rrb:  ", 2);
	ft_putnbr_fd(bench->rrb, 2);
	ft_putstr_fd("  rrr:  ", 2);
	ft_putnbr_fd(bench->rrr, 2);
	ft_putendl_fd("", 2);
}

static void	ft_print_bench(t_bench *bench)
{
	ft_print_disorder(bench->disorder);
	ft_putstr_fd("[bench] strategy:   ", 2);
	ft_putendl_fd(bench->strategy, 2);
	ft_putstr_fd("[bench] total_ops:  ", 2);
	ft_putnbr_fd(bench->total_ops, 2);
	ft_putendl_fd("", 2);
	ft_print_bench_ops(bench);
}

void	ft_sort(t_flags *f, t_stack **a, t_bench *bench)
{
	if (f->simple)
		ft_sort_simple(a, bench);
	else if (f->medium)
		ft_sort_medium(a, bench);
	else if (f->complex)
		ft_sort_complex(a, bench);
	else
		ft_sort_adaptive(a, bench);
}

int	main(int argc, char **argv)
{
	t_flags	f;
	t_stack	*a;
	t_bench	bench;

	a = ft_init_stack('a');
	if (!a)
		ft_error(a);
	ft_init_flags(&f);
	ft_parse_argv(argc, argv, &f, &a);
	ft_init_bench(&bench, a, &f);
	if (ft_is_sorted(a) == 0)
		ft_sort(&f, &a, &bench);
	if (f.bench)
		ft_print_bench(&bench);
	free_stack(a);
	return (0);
}
