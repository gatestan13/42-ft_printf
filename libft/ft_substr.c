/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gatan <gatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 14:09:25 by gatan             #+#    #+#             */
/*   Updated: 2021/05/06 04:10:28 by gatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	if (!s)
		return (NULL);
	res = malloc((sizeof(char) * len) + 1);
	if (res == NULL)
		return (NULL);
	if (start > ft_strlen(s))
	{
		res[0] = '\0';
		return (res);
	}
	i = 0;
	while (i < len)
	{
		res[i] = (*(s + ((size_t)start + i)));
		i++;
	}
	res[i] = '\0';
	return (res);
}
