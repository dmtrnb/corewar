/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 23:28:05 by nhamill           #+#    #+#             */
/*   Updated: 2019/03/25 21:06:13 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strpbrk(const char *s, const char *charset)
{
	char	*p;
	size_t	len;

	p = (char *)s;
	len = ft_strcspn(s, charset);
	if (*(p + len) == 0)
		return (NULL);
	return (p + len);
}
