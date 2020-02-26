/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 18:05:06 by nhamill           #+#    #+#             */
/*   Updated: 2019/04/13 14:14:58 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	void	*p;

	if (!(p = ft_memchr(src, c, n)))
		if (ft_memcpy(dst, src, n))
			return (NULL);
	n = p - src + 1;
	ft_memcpy(dst, src, n);
	return (dst + n);
}
