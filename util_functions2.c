/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_functions2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gatan <gatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 23:44:44 by gatan             #+#    #+#             */
/*   Updated: 2021/05/24 02:24:49 by gatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	count_digits(unsigned int n)
{
	unsigned int	res;

	res = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		res++;
	}
	return (res);
}

char	*ft_ltoa(long n)
{
	unsigned int	res_len;
	long			n_mod;
	char			*res;

	n_mod = (long)n;
	res_len = count_digits(n);
	if (n_mod < 0)
	{
		res_len++;
		n_mod = -n_mod;
	}
	res = malloc(sizeof(char) * (res_len + 1));
	if (res == NULL)
		return (NULL);
	res[res_len--] = '\0';
	if (n < 0)
		res[0] = '-';
	if (n_mod == 0)
		res[res_len] = '0';
	while (n_mod != 0)
	{
		res[res_len--] = (char)((n_mod % 10) + '0');
		n_mod = n_mod / 10;
	}
	return (res);
}

char	*ft_uitoa(unsigned int n)
{
	unsigned int	res_len;
	char			*res;

	res_len = count_digits(n);
	res = malloc(sizeof(char) * (res_len + 1));
	if (res == NULL)
		return (NULL);
	res[res_len--] = '\0';
	if (n == 0)
		res[res_len] = '0';
	while (n != 0)
	{
		res[res_len--] = (char)((n % 10) + '0');
		n = n / 10;
	}
	return (res);
}
