/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 17:55:37 by dholiday          #+#    #+#             */
/*   Updated: 2019/04/17 20:07:37 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	int				i;
	char			*dest;
	char			*sorc;
	char			sy;

	if (!(dst) && !(src))
		return (NULL);
	sy = (unsigned char)c;
	i = -1;
	dest = (char*)dst;
	sorc = (char*)src;
	while (++i < (int)n && sorc[i] != sy)
		dest[i] = sorc[i];
	if (sorc[i] == sy && i != (int)n)
		dest[i] = sorc[i];
	else if ((int)n != 0)
		return (NULL);
	else if (i == (int)n)
		return (NULL);
	return (dest + i + 1);
}
