/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 02:19:57 by nhamill           #+#    #+#             */
/*   Updated: 2019/03/25 21:04:05 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	if (c == 0)
		return ((char *)s + i);
	if (*(s + i) == (char)c)
		return ((char *)s + i);
	while (i)
	{
		if (*(s + i) == (char)c)
			return ((char *)s + i);
		i--;
	}
	if (*(s + i) == (char)c)
		return ((char *)s + i);
	return (NULL);
}
