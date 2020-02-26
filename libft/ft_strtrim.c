/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 02:48:16 by nhamill           #+#    #+#             */
/*   Updated: 2019/04/13 14:35:13 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	while (*(s + i) != 0 && ft_isspace(*(s + i)))
		i++;
	j = ft_strlen(s + i);
	while (j && ft_isspace(*(s + j + i - 1)))
		j--;
	if (!(str = ft_strsub(s, i, j)))
		return (NULL);
	return (str);
}
