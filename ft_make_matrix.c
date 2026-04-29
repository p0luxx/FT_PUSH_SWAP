/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorkgall <gorkgall@42barcelona.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 12:47:17 by gorkgall          #+#    #+#             */
/*   Updated: 2026/04/25 15:13:10 by gorkgall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	size_t	ft_count_words(const char *s)
{
	size_t	words;
	int		in_word;

	words = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != 32 && in_word == 0)
		{
			in_word = 1;
			words++;
		}
		else if (*s == 32)
			in_word = 0;
		s++;
	}
	return (words);
}

static int	ft_strlenwords(char *s)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != 32)
		len++;
	return(len);
}

int	*ft_make_matrix(char *argv)
{
	int	size;
	int	*matrix;
	int	i;
	int	j;

	if (!argv)
		return (NULL);
	size = ft_count_words(argv);
	matrix = (int *)malloc((size + 1) * sizeof(int));
	if (!matrix)
		return (NULL);
	i = 0;
	j = 0;
	while (i < size)
	{
		while (argv[j] == 32 && argv[j] != '-' && argv[j] != '+')
			j++;
		matrix[i] = ft_atoi(&argv[j]);
		j += ft_strlenwords(&argv[j]);
		i++;
	}
	return (matrix);
}

/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		int	*matrix = ft_make_matrix(argv[1]);
		if (!matrix)
			printf("ERROR\n");
		int	i = 0;
		while (i < ft_count_words(argv[1]))
		{
			printf("%d\n", matrix[i]);
			i++;
		}
		free (matrix);
	}
	else
		return (-1);
	return (0);
}*/