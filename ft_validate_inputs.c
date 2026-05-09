/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_inputs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smilitar && gorkgall                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 21:49:07 by smilitar          #+#    #+#             */
/*   Updated: 2026/04/27 23:03:21 by smilitar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//borrrar estoo    sdafaf a fadfafafafafa dfsgddddddddddddddddddddddddddddddddddddddddd
void	ft_print_stack(t_stack *a)
{
	t_node	*tmp;

	if (!a || !a->top)
	{
		printf("[stack '%c' vacío]\n", a ? a->name : '?');
		return ;
	}
	printf("=== STACK '%c' (size: %d) ===\n", a->name, a->size);
	tmp = a->top;
	while (tmp)
	{
		printf("  value: %d\n", tmp->value);
		tmp = tmp->next;
	}
	printf("===========================\n");
}

void	ft_parse_argv(int argc, char **argv, t_flags *f, t_stack **a)
{
	int	i;
	int	flag_count;
	char	*flag_copy;

	i = 1;
	flag_count = 0;
	while (i < argc)
	{
		//printf("la i es: %d\n", i);
		if (ft_is_flag(argv[i]))
		{
			flag_count++;
			if (flag_count > 2)
				ft_error(1);
			if (flag_count == 1)
			{
				flag_copy = ft_strdup(argv[i]);
				ft_select_algorithm(argv[i], f);
			}
			else if (flag_count == 2)
			{
				ft_validate_single_algorithm(flag_copy, argv[i], f);
				if(ft_strncmp(flag_copy, argv[i], ft_strlen(flag_copy)) == 0)
					ft_error(1);
			}
		}
		else
			ft_handle_arg(argv[i], a);
		i++;
	}
	ft_print_stack(*a);
	if (ft_has_duplicates(*a))
	{
		printf("has duplicates");
		ft_error(1);	
	}
}

static void	ft_add_single(char *arg, t_stack **a)
{
	int		value;
	t_node	*node;

	value = ft_atoi(arg);
	node = ft_lstnew(value);
	if (!node)
		ft_error(1);
	ft_lstadd_back(&(*a)->top, node);
	(*a)->size++;
}

static void	ft_add_split(char *arg, t_stack **a)
{
	char	**tokens;
	int		i;
	int		val;
	t_node	*node;

	tokens = ft_split(arg, ' ');
	if (!tokens)
		ft_error(1);
	i = 0;
	while (tokens[i])
	{
		val = ft_atoi(tokens[i]);
		
		node = ft_lstnew(val);
		printf("atoi devuelve %d\n", ft_atoi(tokens[i]));
		if (!node)
		{
			ft_free_split(tokens);
			printf("split");
			ft_error(1);
		}
		ft_lstadd_back(&(*a)->top, node);
		(*a)->size++;
		i++;
	}
	ft_free_split(tokens);
}

void	ft_handle_arg(char *arg, t_stack **a)
{
	if (ft_strchr(arg, ' '))
		ft_add_split(arg, a);
	else
		ft_add_single(arg, a);
}
