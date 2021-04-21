/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 12:38:26 by dholiday          #+#    #+#             */
/*   Updated: 2019/04/06 13:43:04 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int i;
	int j;
	int n;

	n = 0;
	j = 0;
	i = 0;
	while (dst[i] != '\0')
		i++;
	while (src[n] != '\0')
		n++;
	if (i > (int)size - 1)
		return (size + n);
	while (src[j] != '\0' && j + i < (int)size - 1)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (n + i);
}
