/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 12:17:48 by dholiday          #+#    #+#             */
/*   Updated: 2019/04/08 20:58:13 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*str;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
			i++;
		str = (char*)malloc(sizeof(char) * (i + 1));
		if (!(str))
			return (NULL);
		i = 0;
		while (s[i] != '\0')
		{
			str[i] = f(s[i]);
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	else
		return (NULL);
}
