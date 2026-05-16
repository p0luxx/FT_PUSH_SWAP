/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smilitar <smilitar@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 14:12:50 by smilitar          #+#    #+#             */
/*   Updated: 2026/05/16 14:12:51 by smilitar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"

void	error_exit(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}

static void	execute_rotate(char *op, t_stack **a, t_stack **b, t_ctx *ctx)
{
	if (!ft_strncmp(op, "ra", 3))
		op_ra(a, &ctx->c, &ctx->bench);
	else if (!ft_strncmp(op, "rb", 3))
		op_rb(b, &ctx->c, &ctx->bench);
	else if (op[0] == 'r' && op[1] == 'r' && op[2] == '\0')
		op_rr(a, b, &ctx->c, &ctx->bench);
	else if (!ft_strncmp(op, "rra", 4))
		op_rra(a, &ctx->c, &ctx->bench);
	else if (!ft_strncmp(op, "rrb", 4))
		op_rrb(b, &ctx->c, &ctx->bench);
	else if (!ft_strncmp(op, "rrr", 4))
		op_rrr(a, b, &ctx->c, &ctx->bench);
}

void	execute_op(char *op, t_stack **a, t_stack **b)
{
	t_ctx	ctx;

	ctx.c.ops = ctx.buf;
	ctx.c.op_count = 0;
	ft_memset(ctx.buf, 0, 16);
	ft_memset(&ctx.bench, 0, sizeof(t_bench));
	if (!ft_strncmp(op, "sa", 3))
		op_sa(a, &ctx.c, &ctx.bench);
	else if (!ft_strncmp(op, "sb", 3))
		op_sb(b, &ctx.c, &ctx.bench);
	else if (!ft_strncmp(op, "ss", 3))
		op_ss(a, b, &ctx.c, &ctx.bench);
	else if (!ft_strncmp(op, "pa", 3))
		op_pa(a, b, &ctx.c, &ctx.bench);
	else if (!ft_strncmp(op, "pb", 3))
		op_pb(a, b, &ctx.c, &ctx.bench);
	else
		execute_rotate(op, a, b, &ctx);
}

int	is_valid_op(char *op)
{
	if (!ft_strncmp(op, "sa", 3) || !ft_strncmp(op, "sb", 3)
		|| !ft_strncmp(op, "ss", 3) || !ft_strncmp(op, "pa", 3)
		|| !ft_strncmp(op, "pb", 3) || !ft_strncmp(op, "ra", 3)
		|| !ft_strncmp(op, "rb", 3) || !ft_strncmp(op, "rra", 4)
		|| !ft_strncmp(op, "rrb", 4) || !ft_strncmp(op, "rrr", 4))
		return (1);
	if (op[0] == 'r' && op[1] == 'r' && op[2] == '\0')
		return (1);
	return (0);
}
