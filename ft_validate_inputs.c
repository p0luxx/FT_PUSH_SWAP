/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_inputs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smilitar && gorkgall                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 21:49:07 by smilitar          #+#    #+#             */
/*   Updated: 2026/05/12 14:11:39 by gorkgall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_process_flag(char *token, t_parse_ctx *ctx, t_stack **a)
{
	ctx->flag_count++;
	if (ctx->flag_count > 2)
		ft_error(*a);
	if (ctx->flag_count == 1)
	{
		ctx->flag_copy = ft_strdup(token);
		ft_select_algorithm(token, ctx->f, *a);
	}
	else if (ctx->flag_count == 2)
	{
		ft_validate_single_algorithm(ctx->flag_copy, token, ctx->f, a);
		if (ft_strncmp(ctx->flag_copy, token, ft_strlen(ctx->flag_copy)) == 0)
			ft_error(*a);
	}
}

void	ft_add_split(char *arg, t_stack **a, t_parse_ctx *ctx)
{
	char	**tokens;
	int		i;

	tokens = ft_split(arg, ' ');
	if (!tokens || !tokens[0])
	{
		ft_free_split(tokens);
		ft_error(*a);
	}
	i = 0;
	while (tokens[i])
	{
		if (ft_is_flag(tokens[i], a))
			ft_process_flag(tokens[i], ctx, a);
		else
			ft_add_node(a, ft_atol(tokens[i], a));
		i++;
	}
	ft_free_split(tokens);
}

void	ft_handle_arg(char *arg, t_stack **a, t_parse_ctx *ctx)
{
	if (ft_strchr(arg, ' '))
		ft_add_split(arg, a, ctx);
	else if (ft_is_flag(arg, a))
		ft_process_flag(arg, ctx, a);
	else
		ft_add_node(a, ft_atol(arg, a));
}

void	ft_parse_argv(int argc, char **argv, t_flags *f, t_stack **a)
{
	int			i;
	t_parse_ctx	ctx;

	i = 1;
	ctx.f = f;
	ctx.flag_count = 0;
	ctx.flag_copy = NULL;
	while (i < argc)
	{
		if (ft_is_flag(argv[i], a))
			ft_process_flag(argv[i], &ctx, a);
		else
			ft_handle_arg(argv[i], a, &ctx);
		i++;
	}
	if (ft_has_duplicates(*a))
		ft_error(*a);
}
