/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gatan <gatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 15:47:12 by gatan             #+#    #+#             */
/*   Updated: 2021/05/06 04:07:01 by gatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	s1mod;
	unsigned char	s2mod;
	size_t			i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		s1mod = s1[i];
		s2mod = s2[i++];
		if ((s1mod - s2mod) != 0)
			return (s1mod - s2mod);
	}
	return (0);
}
