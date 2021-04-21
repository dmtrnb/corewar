/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 12:23:12 by dholiday          #+#    #+#             */
/*   Updated: 2019/04/06 21:59:33 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *src, size_t len)
{
	int i;
	int j;

	i = 0;
	if (src[0] == '\0')
		return ((char*)str);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == src[j] && src[j] != '\0' &&
				str[i + j] != '\0' && i + j < (int)len)
			j++;
		if (src[j] == '\0')
			return ((char*)&str[i]);
		i++;
	}
	return (NULL);
}
