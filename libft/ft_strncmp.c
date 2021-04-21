/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 12:32:28 by dholiday          #+#    #+#             */
/*   Updated: 2019/04/17 20:39:46 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				i;
	unsigned char	a;
	unsigned char	b;

	i = 0;
	if (s1 == s2)
		return (0);
	while ((s1[i] != '\0' || s2[i] != '\0') && i < (int)n)
	{
		a = s1[i];
		b = s2[i];
		if (a != b)
			return (a - b);
		else
			i++;
	}
	if (i == (int)n)
		return (0);
	return (s1[i] - s2[i]);
}
