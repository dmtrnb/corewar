/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 12:12:41 by dholiday          #+#    #+#             */
/*   Updated: 2019/04/06 12:29:22 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *src)
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
				str[i + j] != '\0')
			j++;
		if (src[j] == '\0')
			return ((char*)&str[i]);
		i++;
	}
	return (NULL);
}
