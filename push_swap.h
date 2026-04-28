/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorkgall <gorkgall@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 12:03:31 by gorkgall          #+#    #+#             */
/*   Updated: 2026/04/28 09:46:36 by gorkgall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* push_swap.h */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

/* ── nodo de la lista enlazada ── */
typedef struct s_node
{
    int             value;   /* valor original */
    int             norm;    /* índice 0..n-1 tras normalizar */
    int             target;  /* posición destino en stack ordenado */
    int             cost_a;  /* rotaciones necesarias en a */
    int             cost_b;  /* rotaciones necesarias en b */
    struct s_node   *next;
    struct s_node   *prev;
}   t_node;

/* ── stack (lista doblemente enlazada) ── */
typedef struct s_stack
{
    t_node  *top;
    t_node  *bottom;
    int     size;
    char    name;    /* 'a' o 'b' para debug */
}   t_stack;

/* ── selector de algoritmo ── */
typedef struct s_flags
{
	int	simple;
	int	medium;
	int	complex;
	int	adaptive;
	int	bench;
}   t_flags;

void	ft_error(int d);
void	ft_validate_single_algorithm(char *selector, t_flags *f);
void	ft_select_algorithm(char *selector, t_flags *f);
void	ft_init_flags(t_flags *f);

void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lastadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list
int	ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
