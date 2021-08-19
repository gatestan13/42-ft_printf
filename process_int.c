/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gatan <gatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 20:05:23 by gatan             #+#    #+#             */
/*   Updated: 2021/05/24 02:40:04 by gatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	process_int_helper2(t_flags flags, char *numstr, int num_ori)
{
	int	length;

	length = 0;
	if (num_ori < 0 && flags.dot >= 0)
		length += putstr_max("-", 1);
	if (flags.dot >= 0)
		length += process_width(flags.dot, ft_strlen(numstr), 1);
	length += putstr_max(numstr, ft_strlen(numstr));
	return (length);
}

static int	process_int_helper(t_flags flags, char *numstr, int num_ori)
{
	int	length;

	length = 0;
	if (flags.dot >= 0 && flags.dot < (int)ft_strlen(numstr))
		flags.dot = ft_strlen(numstr);
	if (flags.dot >= 0)
		flags.width -= flags.dot;
	if (flags.minus == 1)
		length += process_int_helper2(flags, numstr, num_ori);
	if (flags.dot >= 0)
		length += process_width(flags.width, 0, 0);
	else if (flags.dot < 0 && flags.minus == 0)
		length += process_width(flags.width, ft_strlen(numstr), flags.zero);
	else
		length += process_width(flags.width, ft_strlen(numstr), 0);
	if (flags.minus == 0)
		length += process_int_helper2(flags, numstr, num_ori);
	return (length);
}

int	process_int(t_flags flags, int num)
{
	int		length;
	int		num_ori;
	long	num_mod;
	char	*numstr;

	length = 0;
	num_ori = num;
	num_mod = num;
	if (flags.dot == 0 && num == 0)
	{
		length += process_width(flags.width, 0, 0);
		return (length);
	}
	if (num < 0)
	{
		if (flags.dot == -1)
			length += putstr_max("-", 1);
		num_mod *= -1;
		flags.width--;
	}
	numstr = ft_ltoa(num_mod);
	length += process_int_helper(flags, numstr, num_ori);
	free(numstr);
	return (length);
}
