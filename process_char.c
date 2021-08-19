/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gatan <gatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 22:14:53 by gatan             #+#    #+#             */
/*   Updated: 2021/05/23 18:47:21 by gatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	process_char(t_flags *flags, char c)
{
	int	length;

	length = 0;
	if (flags->minus == 1)
		ft_putchar_fd(c, 1);
	length += process_width(flags->width, 1, 0);
	if (flags->minus == 0)
		ft_putchar_fd(c, 1);
	return (length + 1);
}
