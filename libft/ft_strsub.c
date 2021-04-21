/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 13:27:00 by dholiday          #+#    #+#             */
/*   Updated: 2020/03/10 20:03:30 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*str;

	i = 0;
	if (s)
	{
		str = (char*)malloc(sizeof(char) * (len + 1));
		if (!(str))
			return (NULL);
		while (i < (int)len)
		{
			str[i] = s[(int)start + i];
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
