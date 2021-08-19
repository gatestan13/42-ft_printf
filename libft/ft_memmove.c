/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gatan <gatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 19:27:44 by gatan             #+#    #+#             */
/*   Updated: 2021/05/06 04:05:44 by gatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dest_mod;
	const unsigned char	*src_mod;

	if (!dst && !src)
		return (dst);
	dest_mod = dst;
	src_mod = src;
	if (src < dst)
	{
		dest_mod += len;
		src_mod += len;
		while (len--)
			*--dest_mod = *--src_mod;
	}
	else
	{
		while (len--)
			*dest_mod++ = *src_mod++;
	}
	return (dst);
}
