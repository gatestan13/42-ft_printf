/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gatan <gatan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 17:29:16 by gatan             #+#    #+#             */
/*   Updated: 2021/04/28 17:35:54 by gatan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	int	res;

	res = 0;
	if (c >= 0 && c <= 127)
		res = 1;
	return (res);
}