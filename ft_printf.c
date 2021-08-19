/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gatan <gatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 13:23:40 by gatan             #+#    #+#             */
/*   Updated: 2021/05/24 00:16:49 by gatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	init_flags(void)
{
	t_flags	flags;

	flags.dot = -1;
	flags.minus = 0;
	flags.star = 0;
	flags.type = 0;
	flags.width = 0;
	flags.zero = 0;
	return (flags);
}

void	parse_flags(int *i, char *input, t_flags *flags, va_list ap)
{
	while (input[*i])
	{
		if (!ft_isdigit(input[*i]) && !is_type(input[*i]) && \
			!is_flag(input[*i]))
			break ;
		if (input[*i] == '0' && flags->minus == 0)
			flags->zero = 1;
		if (input[*i] == '.')
			set_dot(flags, ap, input, i);
		if (input[*i] == '-')
			set_minus(flags);
		if (ft_isdigit(input[*i]) && input[*i] != '0')
			set_width(flags, input, i);
		if (input[*i] == '*')
			set_star(flags, ap);
		if (is_type(input[*i]))
		{
			flags->type = input[*i];
			break ;
		}
		*i = *i + 1;
	}
}

int	process_input(char *input, va_list ap)
{
	int		i;
	int		length;
	t_flags	flags;

	i = 0;
	length = 0;
	while (1)
	{
		flags = init_flags();
		if (!input[i])
			break ;
		if (input[i] == '%' && input[i + 1])
		{
			i++;
			parse_flags(&i, input, &flags, ap);
			if (is_type(input[i]))
				length += process_types(&flags, ap, input[i]);
			else if (input[i])
				length += putstr_max(&input[i], 1);
		}
		else if (input[i] != '%')
			length += putstr_max(&input[i], 1);
		i++;
	}
	return (length);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	char	*input;
	int		length;

	input = ft_strdup(str);
	length = 0;
	va_start(ap, str);
	length += process_input(input, ap);
	va_end(ap);
	free(input);
	return (length);
}
