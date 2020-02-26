/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 15:44:28 by nhamill           #+#    #+#             */
/*   Updated: 2019/04/12 18:53:31 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*str;

	if (s && f)
	{
		i = 0;
		if (!(str = ft_strdup(s)))
			return (NULL);
		while (*(str + i) != 0)
		{
			*(str + i) = (*f)(*(str + i));
			i++;
		}
		return (str);
	}
	return (NULL);
}
