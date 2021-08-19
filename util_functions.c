/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gatan <gatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 03:15:06 by gatan             #+#    #+#             */
/*   Updated: 2021/05/24 00:08:40 by gatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putstr_max(char *str, int max)
{
	int	i;

	i = 0;
	while (i < max && str[i])
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
	return (i);
}

char	*str_tolower(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}

static char	*ull_to_base_0case(void)
{
	char	*res;

	res = malloc(sizeof(char) * 2);
	if (res == NULL)
		return (NULL);
	res[0] = '0';
	res[1] = '\0';
	return (res);
}

static char	*ull_to_base_fillres(char *res, int i, char base_store[100])
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

char	*ull_to_base(unsigned long long ull, int base)
{
	char	base_store[100];
	char	*res;
	int		i;
	int		temp;

	i = 0;
	if (ull == 0)
	{
		res = ull_to_base_0case();
		return (res);
	}
	while (ull != 0)
	{
		temp = ull % base;
		if (temp < 10)
			base_store[i++] = temp + '0';
		else
			base_store[i++] = temp + ('A' - 10);
		ull /= base;
	}
	res = malloc(sizeof(char) * (i + 1));
	if (res == NULL)
		return (NULL);
	res = ull_to_base_fillres(res, i, base_store);
	return (res);
}
