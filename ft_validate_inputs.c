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

//ft_is_flag
//ft_handle_arg
/*
	si hay numeros como argumentos, leerlos y rellenar con ft_atoi el stack a

	si hay un string, variable o archivo, 
	leerlo y hacer ft_strtim y rellenar con ft_atoi el stack a
*/
//ft_has_duplicates
