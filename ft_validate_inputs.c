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
	(void)a;
	/*while (i < argc)
	{
		ft_handle_arg(argv[i], a);
		i++;
	}
	if (ft_has_duplicates(*a))
		ft_error(1);*/
}

size_t	ft_matrix_size(int *matrix)
{
	size_t	i;

	i = 0;
	while (matrix[i] != NULL)
		i++;
	return (i)
}

t_node	*ft_handle_arg(char *argv, t_stack **a)
{
	size_t	i;
	size_t	flag;
	size_t	size;
	int		*matrix;
	int		temp;
	t_node	**new_list;

	i = 0;
	flag = 0;
	martrix = NULL;
	new_list = NULL;
	size = 0;
	temp = 0;
	while (argv[i++])
	{
		if (argv[i] == 32)
		{
			flag = 1;
			break;
		}
	}

	if (flag)
	{
		matrix = ft_make_matrix(argv);
		if (!matrix)
		{
			// crear funcion para liberar array de enteros
			return ;
		}
		size = ft_matrix_size(matrix);
		ft_make_map(matrix, new_list, size);
		(*a) -> top = new_list;
	}
	else
	{
		temp = ft_atoi(argv);
		new_list = ft_lstnew(temp);
		if (!new_list)
		{
			free(new_list);
			return ;
		}
		ft_lstaddback(a, new_list);
	}
	return (new_list);
}