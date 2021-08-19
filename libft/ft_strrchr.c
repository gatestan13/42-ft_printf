/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gatan <gatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 17:24:49 by gatan             #+#    #+#             */
/*   Updated: 2021/05/06 04:07:10 by gatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		slen;

	slen = ft_strlen(s);
	i = 0;
	while (i <= slen)
	{
		if (s[slen - i] == (unsigned char)c)
			return ((char *)(&s[slen - i]));
		i++;
	}
	return (NULL);
}
