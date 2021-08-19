/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_types.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gatan <gatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 22:08:56 by gatan             #+#    #+#             */
/*   Updated: 2021/05/24 02:37:15 by gatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	process_types(t_flags *flags, va_list ap, int c)
{
	int	length;

	length = 0;
	if (c == 'c')
		length += process_char(flags, va_arg(ap, int));
	if (c == 's')
		length += process_str(*flags, va_arg(ap, char *));
	if (c == 'p')
		length += process_point(*flags, va_arg(ap, unsigned long long));
	if (c == 'd' || c == 'i')
		length += process_int(*flags, va_arg(ap, int));
	if (c == 'u')
		length += process_uint(*flags, va_arg(ap, unsigned int));
	if (c == 'x')
		length += process_hex(*flags, va_arg(ap, unsigned int), 0);
	if (c == 'X')
		length += process_hex(*flags, va_arg(ap, unsigned int), 1);
	if (c == '%')
		length += process_percent(*flags);
	return (length);
}
