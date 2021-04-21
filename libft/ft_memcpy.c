/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:27:11 by dholiday          #+#    #+#             */
/*   Updated: 2019/04/17 20:12:24 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int		i;
	char	*dest;
	char	*sorc;

	i = 0;
	dest = (char*)dst;
	sorc = (char*)src;
	if (dst == src)
		return (dest);
	while (i < (int)n)
	{
		dest[i] = sorc[i];
		i++;
	}
	return (dest);
}
