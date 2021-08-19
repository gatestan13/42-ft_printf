/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_functions3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gatan <gatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 02:20:10 by gatan             #+#    #+#             */
/*   Updated: 2021/05/24 02:27:03 by gatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ui_to_base_0case(void)
{
	char	*res;

	res = malloc(sizeof(char) * 2);
	if (res == NULL)
		return (NULL);
	res[0] = '0';
	res[1] = '\0';
	return (res);
}

static char	*ui_to_base_fillres(char *res, int i, char base_store[100])
{
	int	j;

	j = 0;
	while (j < i)
	{
		res[j] = base_store[(i - 1) - j];
		j++;
	}
	res[j] = '\0';
	return (res);
}

char	*ui_to_base(unsigned int uint, int base)
{
	char	base_store[100];
	char	*res;
	int		i;
	int		temp;

	i = 0;
	if (uint == 0)
	{
		res = ui_to_base_0case();
		return (res);
	}
	while (uint != 0)
	{
		temp = uint % base;
		if (temp < 10)
			base_store[i++] = temp + '0';
		else
			base_store[i++] = temp + ('A' - 10);
		uint /= base;
	}
	res = malloc(sizeof(char) * (i + 1));
	if (res == NULL)
		return (NULL);
	res = ui_to_base_fillres(res, i, base_store);
	return (res);
}
