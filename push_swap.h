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

/* ── flags ── */
typedef struct s_parse_ctx
{
	t_flags	*f;
	int		flag_count;
	char	*flag_copy;
}	t_parse_ctx;

int		ft_strncmp(const char *s1, const char *s2, size_t n);

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

/* ── string utilities ── */

char	**ft_split(char const *s, char c);
int		ft_atoi(char *s, t_stack **a);
int		ft_is_num(char c);
void	ft_free_split(char **split);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strdup(const char *src);
size_t	ft_strlen(const char	*str);

/* ── permited movements ── */

void    ft_sa(t_stack *a);
void    ft_sb(t_stack *b);
void    ft_ss(t_stack *a, t_stack *b);

/* ── sort algorithms ── */

void    ft_sort_simple(t_stack **a);

#endif
