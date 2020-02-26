/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 16:26:10 by nhamill           #+#    #+#             */
/*   Updated: 2019/04/12 20:02:54 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;
	char	*h;

	if (*needle == 0)
		return ((char *)haystack);
	if (*haystack == 0)
		return (NULL);
	i = 0;
	j = 0;
	while (*(haystack + i) != 0 && *(needle + j) != 0)
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
	return ((char *)(haystack + i - 1));
}
