/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gatan <gatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 18:50:44 by gatan             #+#    #+#             */
/*   Updated: 2021/05/24 00:07:00 by gatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_type(char c)
{
	char	type_list[9];
	int		i;

	type_list[0] = 'c';
	type_list[1] = 's';
	type_list[2] = 'p';
	type_list[3] = 'd';
	type_list[4] = 'i';
	type_list[5] = 'u';
	type_list[6] = 'x';
	type_list[7] = 'X';
	type_list[8] = '%';
	i = 0;
	while (i < 9)
	{
		if (c == type_list[i])
			return (1);
		i++;
	}
	return (0);
}

int	is_flag(char c)
{
	char	flag_list[5];
	int		i;

	flag_list[0] = '-';
	flag_list[1] = '0';
	flag_list[2] = '.';
	flag_list[3] = '*';
	flag_list[4] = ' ';
	i = 0;
	while (i < 5)
	{
		if (c == flag_list[i])
			return (1);
		i++;
	}
	return (0);
}
