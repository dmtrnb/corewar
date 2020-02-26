/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasechr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 02:19:57 by nhamill           #+#    #+#             */
/*   Updated: 2020/01/18 13:20:25 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strcasechr(const char *s, int c)
{
	size_t	i;
	int		cases;

	i = 0;
	cases = (c > 64 && c < 91 ? 32 : 0);
	cases = (c > 96 && c < 123 && cases == 0 ? -32 : cases);
	if (cases == 0)
		return (ft_strchr(s, c));
	while (*(s + i) != 0)
	{
		if (*(s + i) == (char)c || *(s + i) == (char)(c + cases))
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
