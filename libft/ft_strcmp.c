/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 03:07:18 by nhamill           #+#    #+#             */
/*   Updated: 2019/04/12 19:44:10 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	help_cmp(const char *s1, const char *s2, size_t i)
{
	while (1)
	{
		if (*(s1 + i + 0) != *(s2 + i + 0) || *(s1 + i + 0) == 0)
			return (i);
		if (*(s1 + i + 1) != *(s2 + i + 1) || *(s1 + i + 1) == 0)
			return (i + 1);
		if (*(s1 + i + 2) != *(s2 + i + 2) || *(s1 + i + 2) == 0)
			return (i + 2);
		if (*(s1 + i + 3) != *(s2 + i + 3) || *(s1 + i + 3) == 0)
			return (i + 3);
		if (*(s1 + i + 4) != *(s2 + i + 4) || *(s1 + i + 4) == 0)
			return (i + 4);
		if (*(s1 + i + 5) != *(s2 + i + 5) || *(s1 + i + 5) == 0)
			return (i + 5);
		if (*(s1 + i + 6) != *(s2 + i + 6) || *(s1 + i + 6) == 0)
			return (i + 6);
		if (*(s1 + i + 7) != *(s2 + i + 7) || *(s1 + i + 7) == 0)
			return (i + 7);
		i += 8;
	}
	return (i);
}

int				ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = help_cmp(s1, s2, 0);
	while (*(s1 + i) == *(s2 + i) && *(s1 + i) != 0)
		i++;
	return (*((unsigned char *)s1 + i) - *((unsigned char *)s2 + i));
}
