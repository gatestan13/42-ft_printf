/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_uint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gatan <gatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 00:19:27 by gatan             #+#    #+#             */
/*   Updated: 2021/05/24 00:45:36 by gatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	process_uint_helper2(t_flags flags, char *numstr)
{
	int	length;

	length = 0;
	if (flags.dot >= 0)
		length += process_width(flags.dot, ft_strlen(numstr), 1);
	length += putstr_max(numstr, ft_strlen(numstr));
	return (length);
}

static int	process_uint_helper(t_flags flags, char *numstr)
{
	int	length;

	length = 0;
	if (flags.dot >= 0 && flags.dot < (int)ft_strlen(numstr))
		flags.dot = ft_strlen(numstr);
	if (flags.dot >= 0)
		flags.width -= flags.dot;
	if (flags.minus == 1)
		length += process_uint_helper2(flags, numstr);
	if (flags.dot >= 0)
		length += process_width(flags.width, 0, 0);
	else if (flags.dot < 0 && flags.minus == 0)
		length += process_width(flags.width, ft_strlen(numstr), flags.zero);
	else
		length += process_width(flags.width, ft_strlen(numstr), 0);
	if (flags.minus == 0)
		length += process_uint_helper2(flags, numstr);
	return (length);
}

int	process_uint(t_flags flags, unsigned int num)
{
	int		length;
	char	*numstr;

	length = 0;
	if (flags.dot == 0 && num == 0)
	{
		length += process_width(flags.width, 0, 0);
		return (length);
	}
	numstr = ft_uitoa(num);
	length += process_uint_helper(flags, numstr);
	free(numstr);
	return (length);
}
