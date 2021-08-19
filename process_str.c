/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gatan <gatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 14:50:38 by gatan             #+#    #+#             */
/*   Updated: 2021/05/23 18:47:41 by gatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	process_str_helper(char *str, t_flags flags)
{
	int	length;

	length = 0;
	if (flags.dot >= 0)
		length += putstr_max(str, flags.dot);
	else
		length += putstr_max(str, ft_strlen(str));
	return (length);
}

int	process_str(t_flags flags, char *str)
{
	int	length;

	length = 0;
	if (!str)
		str = "(null)";
	if (flags.dot >= 0 && flags.dot > (int)ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.minus == 1)
		length += process_str_helper(str, flags);
	if (flags.dot >= 0)
		length += process_width(flags.width, flags.dot, 0);
	else
		length += process_width(flags.width, ft_strlen(str), 0);
	if (flags.minus == 0)
		length += process_str_helper(str, flags);
	return (length);
}
