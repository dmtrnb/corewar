/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 02:40:00 by nhamill           #+#    #+#             */
/*   Updated: 2019/03/25 20:28:21 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swab(const void *src, void *dest, ssize_t nbytes)
{
	nbytes = (nbytes % 2 == 0 ? nbytes : nbytes - 1);
	while (nbytes > 1)
	{
		*((unsigned char *)dest + nbytes - 1) = \
				*((unsigned char *)src + nbytes - 2);
		*((unsigned char *)dest + nbytes - 2) = \
				*((unsigned char *)src + nbytes - 1);
		nbytes -= 2;
	}
}
