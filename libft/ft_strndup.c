/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 22:08:50 by nhamill           #+#    #+#             */
/*   Updated: 2019/03/25 21:17:10 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	i;
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	i = 0;
	while (i != n)
	{
		*(str + i) = *((char *)s1 + i);
		i++;
	}
	*(str + i) = 0;
	return (str);
}
