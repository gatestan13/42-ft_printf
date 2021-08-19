/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gatan <gatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 19:50:36 by gatan             #+#    #+#             */
/*   Updated: 2021/05/23 23:53:43 by gatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_dot(t_flags *flags, va_list ap, char *input, int *i)
{
	char	*dig_len;

	*i = *i + 1;
	if (input[*i] == '*')
	{
		flags->dot = va_arg(ap, int);
		*i = *i + 1;
	}
	else
	{
		flags->dot = 0;
		if (ft_isdigit(input[*i]))
		{
			flags->dot = ft_atoi(&(input[*i]));
			dig_len = ft_itoa(flags->dot);
			*i += (int)(ft_strlen(dig_len));
			free(dig_len);
		}
	}
}

void	set_minus(t_flags *flags)
{
	flags->minus = 1;
	flags->zero = 0;
}

void	set_star(t_flags *flags, va_list ap)
{
	flags->star = 1;
	flags->width = va_arg(ap, int);
	if (flags->width < 0)
	{
		flags->minus = 1;
		flags->width *= -1;
	}
}

void	set_width(t_flags *flags, char *input, int *i)
{
	char	*dig_len;

	if (flags->star == 1)
		flags->width = 0;
	flags->width = ft_atoi(&(input[*i]));
	dig_len = ft_itoa(flags->width);
	*i += (((int)ft_strlen(dig_len)) - 1);
	free(dig_len);
}
