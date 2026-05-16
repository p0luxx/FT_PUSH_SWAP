/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smilitar <smilitar@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 14:13:24 by smilitar          #+#    #+#             */
/*   Updated: 2026/05/16 14:13:28 by smilitar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

int		is_valid_op(char *op);
void	execute_op(char *op, t_stack **a, t_stack **b);
void	error_exit(t_stack *a, t_stack *b);

#endif