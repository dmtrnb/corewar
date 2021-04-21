/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 13:19:17 by dholiday          #+#    #+#             */
/*   Updated: 2019/04/08 13:26:12 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int				i;
	unsigned char	a;
	unsigned char	b;

	i = 0;
	if (s1 && s2)
	{
		while ((s1[i] != '\0' || s2[i] != '\0') && i < (int)n)
		{
			a = s1[i];
			b = s2[i];
			if (a != b)
				return (0);
			else
				i++;
		}
		return (1);
	}
	return (0);
}
