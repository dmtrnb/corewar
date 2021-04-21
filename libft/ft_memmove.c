/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 15:57:43 by dholiday          #+#    #+#             */
/*   Updated: 2019/04/23 19:29:05 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest;
	char	*sorc;
	int		i;

	dest = (char*)dst;
	sorc = (char*)src;
	i = 0;
	if (sorc > dest)
		while (i < (int)len)
		{
			dest[i] = sorc[i];
			i++;
		}
	else if (sorc < dest)
	{
		i = (int)len - 1;
		while (i >= 0)
		{
			dest[i] = sorc[i];
			i--;
		}
	}
	return (dest);
}
