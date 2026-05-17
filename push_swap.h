/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorkgall <gorkgall@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 12:03:31 by gorkgall          #+#    #+#             */
/*   Updated: 2026/05/17 15:08:27 by polux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* push_swap.h */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stddef.h>
# include <stdio.h>

/* ── nodo de la lista enlazada ── */
typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

/* ── stack (lista doblemente enlazada) ── */
typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
	char	name;
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

/* ── bench ── */

typedef struct s_bench
{
	double	disorder;
	char	*strategy;
	int		total_ops;
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
}	t_bench;

/* ── count operations ── */

typedef struct s_count
{
	char	*ops;
	int		op_count;
	t_bench	*bench;
}	t_count;

/* ── flags ── */

typedef struct s_parse_ctx
{
	t_flags	*f;
	int		flag_count;
	char	*flag_copy;
}	t_parse_ctx;

/* ── checker operation context ── */

typedef struct s_ctx
{
	t_count	c;
	t_bench	bench;
	char	buf[16];
}	t_ctx;

/* ── handle errors ── */
void	ft_error(t_stack *a);
void	free_stack(t_stack *a);

/* ── validate flags ── */

void	ft_init_flags(t_flags *f);
void	ft_select_algorithm(char *selector, t_flags *f, t_stack *a);
void	ft_validate_single_algorithm(char *selector1, char *selector2,
			t_flags *f, t_stack **a);
int		ft_is_flag(char *s, t_stack **a);

/* ── parse arguments ── */

void	ft_handle_arg(char *arg, t_stack **a, t_parse_ctx *ctx);
void	ft_parse_argv(int argc, char **argv, t_flags *f, t_stack **a);
int		ft_has_duplicates(t_stack *a);
void	ft_add_split(char *arg, t_stack **a, t_parse_ctx *ctx);

/* ── list utilities ── */

t_node	*ft_lstnew(int content);
void	ft_lstadd_back(t_node **lst, t_node *new);
void	ft_lstadd_front(t_node **lst, t_node *new);
t_node	*ft_lstlast(t_node *lst);
int		ft_lstsize(t_node *lst);
void	ft_lstdelone(t_node *lst);
void	ft_lstclear(t_node **lst);
t_stack	*ft_init_stack(char name);
void	ft_add_node(t_stack **a, int val);
int		ft_is_sorted(t_stack *a);

/* ── string utilities ── */

char	**ft_split(char const *s, char c);
int		ft_atol(char *s, t_stack **a);
int		ft_is_num(char c);
void	ft_free_split(char **split);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strdup(const char *src);
void	*ft_memset(void *s, int c, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t siz);
void	*ft_memcpy(void *dest, const void *src, size_t n);

/* ── permited movements ── */

void	ft_sa(t_stack *a);
void	ft_sb(t_stack *b);
void	ft_ss(t_stack *a, t_stack *b);

/* ── swap operations ── */

void	op_sa(t_stack **a, t_count *c, t_bench *bench);
void	op_sb(t_stack **b, t_count *c, t_bench *bench);
void	op_ss(t_stack **a, t_stack **b, t_count *c, t_bench *bench);

/* ── push operations ── */
void	op_pa(t_stack **a, t_stack **b, t_count *c, t_bench *bench);
void	op_pb(t_stack **a, t_stack **b, t_count *c, t_bench *bench);

/* ── rotate operations ── */
void	op_ra(t_stack **a, t_count *c, t_bench *bench);
void	op_rb(t_stack **b, t_count *c, t_bench *bench);
void	op_rr(t_stack **a, t_stack **b, t_count *c, t_bench *bench);

/* ── reverse rotate operations ── */
void	op_rra(t_stack **a, t_count *c, t_bench *bench);
void	op_rrb(t_stack **b, t_count *c, t_bench *bench);
void	op_rrr(t_stack **a, t_stack **b, t_count *c, t_bench *bench);

/* ── stack helpers ── */
t_stack	*stack_pop(t_stack **stack);
void	stack_add_front(t_stack **stack, t_stack *new);
void	stack_add_back(t_stack **stack, t_stack *new);
void	record_operation(char *ops, int *count, const char *op);
void	print_ops(char *ops, int count);

/* ── sort algorithms ── */

void	ft_sort_simple(t_stack **a, t_bench *bench);
void	ft_sort_medium(t_stack **a, t_bench *bench);
void	ft_sort_complex(t_stack **a, t_bench *bench);
void	ft_sort_adaptive(t_stack **a, t_bench *bench);
void	ft_sort_small(t_stack **a, t_bench *bench);
/* ── sort utils algorithms ── */

int		get_index(t_node *stack, int value);
int		find_max(t_node *stack);
void	rotate_val_to_top_b(t_stack **s, int val, t_count *c, t_bench *bench);
void	rotate_val_to_top_a(t_stack **s, int val, t_count *c, t_bench *bench);
int		ft_sqrt(int n);
int		get_max_bits(int max_num);
int		get_max_value(t_node *stack);
void	normalize_stack(t_stack **stack);

/* ── validate bench ── */

void	ft_init_bench(t_bench *bench, t_stack *a, t_flags *f);

#endif
