/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 18:36:12 by nhamill           #+#    #+#             */
/*   Updated: 2019/03/24 19:48:06 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int		dif;
	size_t	i;

	i = 0;
	while (i != n && *((unsigned char *)s1 + i) == *((unsigned char *)s2 + i))
		i++;
	if (i == n)
		return (0);
	dif = *((unsigned char *)s1 + i) - *((unsigned char *)s2 + i);
	return (dif);
}
