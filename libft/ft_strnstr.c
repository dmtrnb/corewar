/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 16:26:10 by nhamill           #+#    #+#             */
/*   Updated: 2019/04/12 20:26:43 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*h;

	if (*needle == 0)
		return ((char *)haystack);
	i = 0;
	j = 0;
	h = (char *)haystack;
	while (*(haystack + i) != 0 && i < len && *(needle + j) != 0)
	{
		j = 0;
		if ((h = ft_strchr((haystack + i), *(needle + j))))
		{
			i += h - (haystack + i);
			while (*(h + j) == *(needle + j) && *(needle + j) != 0)
				j++;
		}
		else
			return (NULL);
		i++;
	}
	if (i + j - 1 > len || *haystack == 0)
		return (NULL);
	return ((char *)(haystack + i - 1));
}
