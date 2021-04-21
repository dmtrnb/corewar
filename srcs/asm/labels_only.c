/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   labels_only.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2020/03/07 15:38:28 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_labels_only(char *str)
{
	char	*temp;
	int		i;
	int		index;

	i = 0;
	index = 0;
	temp = NULL;
	while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
	{
		if ((str[i] == '\0' || str[i] == ' ' || str[i] == '\t') && index == 0)
			return (NULL);
		if (str[i] == LABEL_CHAR && (i != 0) && str[i - 1] != DIRECT_CHAR)
		{
			if (str[i + 1] == ' ' || str[i + 1] == '\t')
				return (ft_labels_only2(str, i, 5));
			else
				index = 1;
		}
		i++;
	}
	if (index == 1)
		temp = ft_labels_only2(str, i, index);
	return (temp);
}

char	*ft_labels_only2(char *str, int i, int index)
{
	char c;
	char *temp;

	if (index == 1)
		while (!(str[i] == LABEL_CHAR && str[i - 1] != DIRECT_CHAR))
			i--;
	c = str[i + 1];
	str[i + 1] = '\0';
	temp = ft_strdup(str);
	str[i + 1] = c;
	return (temp);
}
