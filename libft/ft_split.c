/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gatan <gatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 11:18:31 by gatan             #+#    #+#             */
/*   Updated: 2021/05/08 12:37:16 by gatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordlen(char *s, char c)
{
	int		i;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		i++;
		if (*s == '\0')
			i--;
		while (*s && *s != c)
			s++;
	}
	return (i);
}

static char	*fill_next(char const *s, char c)
{
	char	*str;
	int		len;
	int		i;
	int		j;

	i = 0;
	len = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i + len] && s[i + len] != c)
		len++;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	j = 0;
	while (j < len)
	{
		str[j] = s[i + j];
		j++;
	}
	str[len] = '\0';
	return (str);
}

static int	str_start(char const *s, char c)
{
	int		i;

	i = 0;
	while (s[i] && s[i] == c)
		i++;
	return (i);
}

static void	ft_free(char **res, int len)
{
	int		i;

	i = 0;
	while (i < len)
		if (res + i && res[i])
			free(res[i]);
	free(res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	char	*str;
	int		len;
	int		i;

	if (!s)
		return (NULL);
	len = wordlen((char *)s, c);
	res = malloc(sizeof(char *) * (len + 1));
	if (!res)
		return (0);
	i = 0;
	while (i < len)
	{
		str = fill_next(s, c);
		if (!str)
		{
			ft_free(res, i);
			return (0);
		}
		res[i++] = str;
		s += str_start(s, c) + ft_strlen(str);
	}
	res[len] = 0;
	return (res);
}
