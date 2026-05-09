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
//borrrar estoo    sdafaf a fadfafafafafa dfsgddddddddddddddddddddddd
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

static void	ft_process_flag(char *token, t_parse_ctx *ctx)
{
	ctx->flag_count++;
	if (ctx->flag_count > 2)
		ft_error(1);
	if (ctx->flag_count == 1)
	{
		ctx->flag_copy = ft_strdup(token);
		ft_select_algorithm(token, ctx->f);
	}
	else if (ctx->flag_count == 2)
	{
		ft_validate_single_algorithm(ctx->flag_copy, token, ctx->f);
		if (ft_strncmp(ctx->flag_copy, token, ft_strlen(ctx->flag_copy)) == 0)
			ft_error(1);
	}
}

void	ft_add_split(char *arg, t_stack **a, t_parse_ctx *ctx)
{
	char	**tokens;
	int		i;

	tokens = ft_split(arg, ' ');
	if (!tokens)
		ft_error(1);
	i = 0;
	while (tokens[i])
	{
		if (ft_is_flag(tokens[i]))
			ft_process_flag(tokens[i], ctx);
		else
			ft_add_node(a, ft_atoi(tokens[i]), tokens);
		i++;
	}
	ft_free_split(tokens);
}

static void	ft_add_single(char *arg, t_stack **a)
{
	t_node	*node;

	node = ft_lstnew(ft_atoi(arg));
	if (!node)
		ft_error(1);
	ft_lstadd_back(&(*a)->top, node);
	(*a)->size++;
}

void	ft_handle_arg(char *arg, t_stack **a, t_parse_ctx *ctx)
{
	if (ft_strchr(arg, ' '))
		ft_add_split(arg, a, ctx);
	else
		ft_add_single(arg, a);
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
		if (ft_is_flag(argv[i]))
			ft_process_flag(argv[i], &ctx);
		else
			ft_handle_arg(argv[i], a, &ctx);
		i++;
	}
	if (ft_has_duplicates(*a))
		ft_error(1);
	ft_print_stack(*a);
}
