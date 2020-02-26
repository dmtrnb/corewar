/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 16:01:40 by nhamill           #+#    #+#             */
/*   Updated: 2019/04/12 18:57:18 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	size_t		i;

	if (s)
	{
		i = 0;
		while (*(s + i) != 0)
		{
			ft_putchar_fd(*(s + i), fd);
			i++;
		}
		ft_putchar_fd('\n', fd);
	}
}
