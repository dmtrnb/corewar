/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 22:07:22 by nhamill           #+#    #+#             */
/*   Updated: 2020/01/18 13:14:30 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsep(char **stringp, const char *delim)
{
	char	*p;

	if (!(*stringp) || *(*stringp) == 0)
		return (NULL);
	p = (*stringp);
	while (*(*stringp) != 0)
	{
		if (ft_strchr(delim, *(*stringp)))
		{
			*(*stringp) = 0;
			(*stringp)++;
			return (p);
		}
		(*stringp)++;
	}
	return (p);
}
