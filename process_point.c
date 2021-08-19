/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_point.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gatan <gatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 04:28:53 by gatan             #+#    #+#             */
/*   Updated: 2021/05/23 18:47:26 by gatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	process_point_helper(t_flags flags, char *ptr)
{
	int	length;

	length = 0;
	length += putstr_max("0x", 2);
	if (flags.dot >= 0)
	{
		length += process_width(flags.dot, ft_strlen(ptr), 1);
		length += putstr_max(ptr, flags.dot);
	}
	else
		length += putstr_max(ptr, ft_strlen(ptr));
	return (length);
}

int	process_point(t_flags flags, unsigned long long addr)
{
	char	*ptr;
	int		length;

	length = 0;
	if (addr == 0 && flags.dot == 0)
	{
		length += putstr_max("0x", 2);
		return (length += process_width(flags.width, 0, 1));
	}
	ptr = ull_to_base(addr, 16);
	ptr = str_tolower(ptr);
	if (flags.dot < (int)ft_strlen(ptr))
		flags.dot = (int)ft_strlen(ptr);
	if (flags.minus == 1)
		length += process_point_helper(flags, ptr);
	length += process_width(flags.width, ft_strlen(ptr) + 2, 0);
	if (flags.minus == 0)
		length += process_point_helper(flags, ptr);
	free(ptr);
	return (length);
}
