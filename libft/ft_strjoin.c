/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 13:37:55 by dholiday          #+#    #+#             */
/*   Updated: 2019/04/08 14:52:29 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!(s1 && s2))
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	str = (char*)malloc(sizeof(char) * (i + j + 1));
	if (!(str))
		return (NULL);
	i = 0;
	j = 0;
	str = ft_strcpy(str, s1);
	str = ft_strcat(str, s2);
	return (str);
}
