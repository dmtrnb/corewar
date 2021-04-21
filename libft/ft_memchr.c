/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:43:38 by dholiday          #+#    #+#             */
/*   Updated: 2019/04/09 22:07:40 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int		i;
	char	*sorc;
	char	sy;

	sy = (unsigned char)c;
	i = 0;
	sorc = (char*)s;
	while (i < (int)n)
	{
		if (sorc[i] == sy)
			return (sorc + i);
		i++;
	}
	return (NULL);
}
