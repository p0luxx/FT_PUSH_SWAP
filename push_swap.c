/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smilitar && gorkgall                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 15:30:54 by smilitar          #+#    #+#             */
/*   Updated: 2026/04/24 10:47:05 by gorkgall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	*selector;
	int		**matrix;

	if (argc <= 1)
		exit(1);
	else if (argc == 2)
	{
		// selector = NULL;
		// checkear: son caracteres numericos? crear funciom ft_atoi_check(argv[1]);
			// if true
				// matrix = split_int(argv[1], space);
			//else
				//exit (-1);
	}
	else if (argc >= 3)
	{
		// selector = argv[2] 
		// checkear: son caracteres numericos? crear funcion ft_atoi_check(argv[1]);
		// if true:
			// matrix = split_int(argv[1], space);
		//else
			//exit (-1);
	}
	// crear funcion para checkear valores unicos
	if (//valores repetidos)
	{
		exit(-1);
		free(matrix);
	}
	else
	{
		if (matrix && selector)
		{
			//crear funcion con argumento selector que decida el algoritmo
			//ex: ft_select_algorithm(matrix, selector);
		}
		else if(matrix && !selector)
		{
			// ft_sort_list(matrix);
		}
		else
			exit(8);
	}
}
