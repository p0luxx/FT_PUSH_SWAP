/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_inputs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smilitar <smilitar@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 21:49:07 by smilitar          #+#    #+#             */
/*   Updated: 2026/04/27 23:03:21 by smilitar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_parse_argv(int argc, char **argv, t_flags *f, t_stack **a)
{
	int	i;
	int	flag_count;

	i = 1;
	flag_count = 0;
	while (i < argc && ft_is_flag(argv[i]))
	{
		flag_count++;
		if (flag_count > 2)
			ft_error(1);
		i++;
	}
	if (flag_count == 1)
		ft_select_algorithm(argv[1], f);
	else if (flag_count == 2)
		ft_validate_single_algorithm(argv[1], argv[2], f);
	if (i >= argc)
		ft_error(1);
	while (i < argc)
		ft_handle_arg(argv[i++], a);
	if (ft_has_duplicates(*a))
		ft_error(1);
}

static void	ft_add_single(char *arg, t_stack **a)
{
	int		value;
	t_node	*node;

	value = ft_atoi(arg);
	node = ft_lstnew(value);
	if (!node)
		ft_error(1);
	ft_lstaddback(a, node);
}

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static void	ft_add_split(char *arg, t_stack **a)
{
	char	**tokens;
	int		i;
	t_node	*node;

	tokens = ft_split(arg, ' ');
	if (!tokens)
		ft_error(1);
	i = 0;
	while (tokens[i])
	{
		node = ft_lstnew(ft_atoi(tokens[i]));
		if (!node)
			ft_error(1);
		ft_lstaddback(a, node);
		i++;
	}
	ft_free_split(tokens);
}

t_node	*ft_handle_arg(char *arg, t_stack **a)
{
	if (ft_strchr(arg, ' '))
		ft_add_split(arg, a);
	else
		ft_add_single(arg, a);
	return (NULL);
}