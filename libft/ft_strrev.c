/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 23:19:33 by nhamill           #+#    #+#             */
/*   Updated: 2019/03/25 21:00:05 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(const char *str)
{
	size_t	i;
	size_t	len;
	char	*rev;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	if (!(rev = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i != len)
	{
		*(rev + i) = *(str + len - i - 1);
		i++;
	}
	*(rev + len) = 0;
	return (rev);
}
