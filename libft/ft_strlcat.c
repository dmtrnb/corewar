/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 01:40:44 by nhamill           #+#    #+#             */
/*   Updated: 2019/04/12 21:34:23 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i;
	int		j;
	size_t	num;
	char	*tmp;

	i = 0;
	j = 0;
	tmp = dst;
	num = size;
	while (*(tmp + i) != '\0' && num != 0 && num-- != 1)
		i++;
	if (size == 0 || *(tmp + i) != '\0')
		return (size - num + ft_strlen(src));
	while (*(src + j) != '\0' && num != 0 && num-- != 1)
	{
		*(tmp + i) = *(src + j);
		i++;
		j++;
	}
	*(tmp + i) = '\0';
	if (*(src + j) != '\0')
		while (*(src + (++j)) != '\0')
			num--;
	return (size - num);
}
