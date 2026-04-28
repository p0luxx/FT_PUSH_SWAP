/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smilitar <smilitar@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 21:48:04 by smilitar          #+#    #+#             */
/*   Updated: 2026/04/27 21:48:06 by smilitar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_init_flags(t_flags *f)
{
	f->simple = 0;
	f->medium = 0;
	f->complex = 0;
	f->adaptive = 1;
	f->bench = 0;
}

void	ft_select_algorithm(char *selector, t_flags *f)
{
	if (!selector)
		return ;
	f->adaptive = 0;
	if (ft_strncmp(selector, "--simple", 9) == 0)
		f->simple = 1;
	else if (ft_strncmp(selector, "--medium", 9) == 0)
		f->medium = 1;
	else if (ft_strncmp(selector, "--complex", 10) == 0)
		f->complex = 1;
	else if (ft_strncmp(selector, "--adaptive", 11) == 0)
		f->adaptive = 1;
	else if (ft_strncmp(selector, "--bench", 8) == 0)
		f->bench = 1;
	else
		ft_error(1);
}

void	ft_validate_single_algorithm(char *selector1, char *selector2, t_flags *f)
{
	int count;

	ft_select_algorithm(selector1, f);
	ft_select_algorithm(selector1, f);
	count = 0;
	if (f->simple)
		count++;
	if (f->medium)
		count++;
	if (f->complex)
		count++;
	if (f->adaptive)
		count++;
	if (count > 1)
		ft_error(1);
}
