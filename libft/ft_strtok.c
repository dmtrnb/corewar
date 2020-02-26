/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 20:10:17 by nhamill           #+#    #+#             */
/*   Updated: 2019/03/28 22:00:50 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtok(char *str, const char *sep)
{
	static char	*p = NULL;

	if (!str && (!p || *p == 0))
		return (NULL);
	if (str)
		p = str;
	if (!str && p)
		str = p;
	while (*p != 0)
	{
		if (ft_strchr(sep, *p))
		{
			while (ft_strchr(sep, *p))
			{
				*p = 0;
				p++;
			}
			return (str);
		}
		p++;
	}
	return (str);
}
