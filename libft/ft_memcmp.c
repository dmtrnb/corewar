/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 20:14:27 by dholiday          #+#    #+#             */
/*   Updated: 2019/04/06 21:58:02 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				i;
	unsigned char	*s11;
	unsigned char	*s22;

	i = 0;
	s11 = (unsigned char*)s1;
	s22 = (unsigned char*)s2;
	while (i < (int)n)
	{
		if (s11[i] != s22[i])
			return (s11[i] - s22[i]);
		else
			i++;
	}
	return (0);
}
