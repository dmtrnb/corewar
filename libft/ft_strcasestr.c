/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasestr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 16:26:10 by nhamill           #+#    #+#             */
/*   Updated: 2020/01/18 13:21:21 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	help(const char *haystack, const char *needle, size_t *i, \
																	char *h)
{
	size_t	j;
	int		l;

	j = 0;
	*i += h - (haystack + *i);
	while (*(needle + j) != 0)
	{
		l = (*(needle + j) > 64 && *(needle + j) < 91 ? 32 : 0);
		l = (*(needle + j) > 96 && *(needle + j) < 123 ? -32 : l);
		if (*(h + j) == *(needle + j) || *(h + j) == *(needle + j + l))
			j++;
		else
			return (j);
	}
	return (j);
}

char			*ft_strcasestr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;
	char	*h;

	if (!needle)
		return ((char *)haystack);
	i = 0;
	j = 0;
	while (*(haystack + i) != 0 && *(needle + j) != 0)
	{
		j = 0;
		if ((h = ft_strcasechr((haystack + i), *(needle + j))))
			j = help(haystack, needle, &i, h);
		else
			return (NULL);
		i++;
	}
	return ((char *)(haystack + i - 1));
}
