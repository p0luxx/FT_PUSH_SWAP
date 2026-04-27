/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_repeat_val.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorkgall <gorkgall@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 12:44:03 by gorkgall          #+#    #+#             */
/*   Updated: 2026/04/27 12:50:24 by gorkgall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_repeat_val(int *matrix)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	flag = 0;
	while (matrix[i])
	{
		j = 0;
		while(matrix[j])
		{
			if (matrix[i] == matrix[j])
				flag = 1;
			j++;
		}
		i++;
	}
	return (flag);
}
