/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncasecmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 03:07:18 by nhamill           #+#    #+#             */
/*   Updated: 2019/03/25 21:24:55 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		cs(const char s1, const char s2)
{
	if (ft_isalpha(s1) && ft_isalpha(s2) && (s1 + 32 == s2 || s1 - 32 == s2))
		return (0);
	return (1);
}

int				ft_strncasecmp(const char *s1, const char *s2, size_t n)
{
	int		res;
	size_t	i;

	i = 0;
	while ((*(s1 + i) == *(s2 + i) || !cs(*(s1 + i), *(s2 + i))) \
			&& *(s1 + i) != 0 && i != n)
		i++;
	if (!cs(*(s1 + i), *(s2 + i)))
		return (0);
	if (ft_isalpha(*(s1 + i)) && ft_isalpha(*(s2 + i)))
	{
		res = (*((unsigned char *)s1 + i) - *((unsigned char *)s2 + i));
		res = (res > 26 ? res - 32 : res);
		res = (res < -26 ? res + 32 : res);
		return (res);
	}
	return (*((unsigned char *)s1 + i) - *((unsigned char *)s2 + i));
}
