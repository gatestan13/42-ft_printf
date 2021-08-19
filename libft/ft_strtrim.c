/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gatan <gatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 16:43:45 by gatan             #+#    #+#             */
/*   Updated: 2021/05/06 04:18:13 by gatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char const *set, char c)
{
	unsigned int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	start_ind(char const *s1, char const *set)
{
	int		res;

	res = 0;
	while (s1)
	{
		if (in_set(set, s1[res]))
			res++;
		else
			break ;
	}
	return (res);
}

static int	end_ind(char const *s1, char const *set, int len)
{
	int		res;

	res = len - 1;
	while (res > 0)
	{
		if (in_set(set, s1[res]))
			res--;
		else
			break ;
	}
	return (res);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		res_len;
	int		s1_len;
	int		i;

	if (!s1)
		return (NULL);
	s1_len = ft_strlen(s1);
	res_len = (end_ind(s1, set, s1_len) - start_ind(s1, set)) + 1;
	if (res_len > 0)
	{
		res = malloc(sizeof(char) * (res_len + 1));
		if (res == NULL)
			return (NULL);
		i = -1;
		while (++i < res_len)
			res[i] = (s1)[i + start_ind(s1, set)];
		res[i] = '\0';
		return (res);
	}
	res = malloc(sizeof(char) * 1);
	if (res == NULL)
		return (NULL);
	res[0] = '\0';
	return (res);
}
