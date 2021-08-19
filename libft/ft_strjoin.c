/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gatan <gatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 15:04:40 by gatan             #+#    #+#             */
/*   Updated: 2021/05/06 04:12:40 by gatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	s1_len;
	unsigned int	s2_len;
	unsigned int	i;
	unsigned int	j;
	char			*res;

	if (!s1)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	res = malloc(sizeof(char) * ((s1_len + s2_len) + 1));
	if (res == NULL)
		return (NULL);
	i = -1;
	while (++i < s1_len)
		res[i] = s1[i];
	j = -1;
	while (++j < s2_len)
		res[i + j] = s2[j];
	res[i + j] = '\0';
	return (res);
}
