/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 00:38:41 by nhamill           #+#    #+#             */
/*   Updated: 2019/04/12 18:29:42 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && *(src + i) != 0)
	{
		*(dst + i) = *(src + i);
		i++;
	}
	if (i != len && *(src + i) == 0)
		while (i < len)
		{
			*(dst + i) = 0;
			i++;
		}
	return (dst);
}
