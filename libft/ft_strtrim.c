/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:52:52 by dholiday          #+#    #+#             */
/*   Updated: 2020/02/26 15:23:49 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		n;
	int		k;
	char	*str;

	n = 0;
	i = -1;
	k = 0;
	if (!(s))
		return (NULL);
	while (s[++i] == ' ' || s[i] == '\n' || s[i] == '\t')
		n++;
	i = (int)ft_strlen(s);
	if (i < 0)
		return (NULL);
	while (s[--i] == ' ' || s[i] == '\n' || s[i] == '\t')
		k++;
	if (n == (int)ft_strlen(s))
		k = 0;
	str = (char*)malloc(sizeof(char) * ((int)ft_strlen(s) - n - k + 1));
	if (!(str))
		return (NULL);
	str = ft_strncpy(str, s + n, (int)ft_strlen(s) - n - k);
	str[(int)ft_strlen(s) - n - k] = '\0';
	return (str);
}
