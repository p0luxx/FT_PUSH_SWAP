/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smilitar <smilitar@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 14:12:29 by smilitar          #+#    #+#             */
/*   Updated: 2026/05/16 14:12:30 by smilitar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"

static char	*read_line(void)
{
	char	buf[1];
	char	line[256];
	int		i;
	int		ret;

	i = 0;
	ret = read(0, buf, 1);
	while ((ret > 0))
	{
		if (buf[0] == '\n')
			break ;
		line[i++] = buf[0];
		if (i >= 255)
			break ;
		ret = read(0, buf, 1);
	}
	if (i == 0 && ret <= 0)
		return (NULL);
	line[i] = '\0';
	return (ft_strdup(line));
}

static void	read_and_execute(t_stack **a, t_stack **b)
{
	char	*line;

	line = read_line();
	while (line)
	{
		if (!is_valid_op(line))
		{
			free(line);
			error_exit(*a, *b);
		}
		execute_op(line, a, b);
		free(line);
		line = read_line();
	}
}

static void	parse_token(char *arg, t_stack **a)
{
	char	**tokens;
	int		j;

	if (ft_strchr(arg, ' '))
	{
		tokens = ft_split(arg, ' ');
		if (!tokens || !tokens[0])
		{
			ft_free_split(tokens);
			ft_error(*a);
		}
		j = 0;
		while (tokens[j])
			ft_add_node(a, ft_atol(tokens[j++], a));
		ft_free_split(tokens);
	}
	else
		ft_add_node(a, ft_atol(arg, a));
}

static void	parse_args(int argc, char **argv, t_stack **a, t_stack **b)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		parse_token(argv[i], a);
		i++;
	}
	if (ft_has_duplicates(*a))
	{
		free_stack(*a);
		free_stack(*b);
		write(2, "Error\n", 6);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = ft_init_stack('a');
	b = ft_init_stack('b');
	if (!a || !b)
		return (1);
	parse_args(argc, argv, &a, &b);
	if (!a->size)
		return (free_stack(a), free_stack(b), 0);
	read_and_execute(&a, &b);
	if (ft_is_sorted(a) && b->size == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(a);
	free_stack(b);
	return (0);
}
