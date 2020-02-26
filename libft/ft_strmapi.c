/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:44:28 by nhamill           #+#    #+#             */
/*   Updated: 2019/04/12 18:53:47 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	if (s && f)
	{
		i = 0;
		if (!(str = ft_strdup(s)))
			return (NULL);
		while (*(str + i) != 0)
		{
			*(str + i) = (*f)(i, *(str + i));
			i++;
		}
		return (str);
	}
	return (NULL);
}
