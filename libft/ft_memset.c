/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 03:00:02 by nhamill           #+#    #+#             */
/*   Updated: 2020/03/07 12:12:57 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long long	get_mask(char c)
{
	unsigned long long	l;

	l = c;
	l |= l << 8 | l << 16 | l << 24 | l << 32 | l << 40 | l << 48 | l << 56;
	return (l);
}

void						*ft_memset(void *b, int c, size_t len)
{
	unsigned long long	l;
	unsigned long long	*ll;

	if (len > sizeof(unsigned long long) * 10)
	{
		l = get_mask(c & 0xff);
		while (len >= 8)
		{
			ll = (unsigned long long *)b;
			*ll = l;
			len -= 8;
			b += 8;
		}
	}
	while (len)
	{
		len--;
		*((unsigned char *)b + len) = (unsigned char)c;
	}
	return (b);
}
