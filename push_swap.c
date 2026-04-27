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

int	main(int argc, char **argv)
{
	char	*selector;
	int		*matrix;

	if (argc <= 1)
		exit(1);
	else if (argc == 2)
	{
		selector = NULL;
		if (ft_is_num(argv[1]) // cambiar mas adelante el nombre de la funcion por ft_is_valid_input
			matrix = ft_make_matrix(argv[1]);
		else
			exit(-1);
	}
	else if (argc >= 3)
	{
		selector = argv[2];
		if (ft_is_num(argv[1])
				matrix = ft_make_matrix(argv[1]);
		else
			exit (-1);
	}
	if (ft_is_repeat_val(matrix))
	{
		free(matrix);
		exit(-8);
	}
	else
	{
		if (matrix && selector)
		{
			//crear funcion con argumento selector que decida el algoritmo
			////ex: ft_select_algorithm(matrix, selector);
		}
		else if(matrix && !selector)
		{
			// ft_sort_list(matrix);
		}
		else
			exit(8);
	}
	free(matrix);
	return (0);
}
