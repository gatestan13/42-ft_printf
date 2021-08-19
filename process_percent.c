/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gatan <gatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 02:32:14 by gatan             #+#    #+#             */
/*   Updated: 2021/05/24 02:44:24 by gatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	process_percent(t_flags flags)
{
	int	length;

	length = 0;
	if (flags.minus == 1)
		length += putstr_max("%", 1);
	length += process_width(flags.width, 1, flags.zero);
	if (flags.minus == 0)
		length += putstr_max("%", 1);
	return (length);
}
