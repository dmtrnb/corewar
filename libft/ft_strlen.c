/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 02:32:18 by nhamill           #+#    #+#             */
/*   Updated: 2019/03/24 19:56:41 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*(s + len) != 0)
	{
		if (*(s + len + 1) == 0)
			return (len + 1);
		if (*(s + len + 2) == 0)
			return (len + 2);
		if (*(s + len + 3) == 0)
			return (len + 3);
		if (*(s + len + 4) == 0)
			return (len + 4);
		if (*(s + len + 5) == 0)
			return (len + 5);
		if (*(s + len + 6) == 0)
			return (len + 6);
		if (*(s + len + 7) == 0)
			return (len + 7);
		len += 8;
	}
	return (len);
}
