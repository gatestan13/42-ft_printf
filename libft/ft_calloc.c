/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gatan <gatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 20:36:57 by gatan             #+#    #+#             */
/*   Updated: 2021/05/06 04:04:32 by gatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*res;
	size_t	i;

	res = NULL;
	res = malloc(count * size);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < (count * size))
	{
		res[i] = '\0';
		i++;
	}
	return (res);
}
