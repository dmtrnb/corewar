/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 03:00:02 by nhamill           #+#    #+#             */
/*   Updated: 2019/03/24 20:24:24 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	while (len >= 8)
	{
		len -= 8;
		*((unsigned char *)b + len + 7) = (unsigned char)c;
		*((unsigned char *)b + len + 6) = (unsigned char)c;
		*((unsigned char *)b + len + 5) = (unsigned char)c;
		*((unsigned char *)b + len + 4) = (unsigned char)c;
		*((unsigned char *)b + len + 3) = (unsigned char)c;
		*((unsigned char *)b + len + 2) = (unsigned char)c;
		*((unsigned char *)b + len + 1) = (unsigned char)c;
		*((unsigned char *)b + len + 0) = (unsigned char)c;
	}
	while (len)
	{
		len--;
		*((unsigned char *)b + len) = (unsigned char)c;
	}
	return (b);
}
