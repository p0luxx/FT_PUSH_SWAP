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

/* push_swap.h */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stddef.h>

/* ── nodo de la lista enlazada ── */
typedef struct s_node
{
	int				value;/* valor original */
	int				norm;/* índice 0..n-1 tras normalizar */
	int				target;/* posición destino en stack ordenado */
	int				cost_a;/* rotaciones necesarias en a */
	int				cost_b;/* rotaciones necesarias en b */
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

/* ── stack (lista doblemente enlazada) ── */
typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
	char	name;/* 'a' o 'b' para debug */
}	t_stack;

/* ── selector de algoritmo ── */
typedef struct s_flags
{
	int	simple;
	int	medium;
	int	complex;
	int	adaptive;
	int	bench;
}	t_flags;

int		ft_strncmp(const char *s1, const char *s2, size_t n);

/* ── handle errors ── */
void	ft_error(int d);

/* ── validate flags ── */

void	ft_init_flags(t_flags *f);
void	ft_select_algorithm(char *selector, t_flags *f);
void	ft_validate_single_algorithm(char *selector1, char *selector2,
			t_flags *f);
int		ft_is_flag(char *s);

/* ── parse arguments ── */

void	ft_parse_argv(int argc, char **argv, t_flags *f, t_stack **a);

#endif
