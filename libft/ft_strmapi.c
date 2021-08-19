/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gatan <gatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 17:09:23 by gatan             #+#    #+#             */
/*   Updated: 2021/05/06 04:19:42 by gatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	s_len;
	unsigned int	i;
	char			*res;

	if (!s)
		return (NULL);
	s_len = 0;
	while (s[s_len])
		s_len++;
	res = malloc(sizeof(char) * (s_len + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < s_len)
	{
		res[i] = (char)s[i];
		res[i] = (*f)(i, res[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
