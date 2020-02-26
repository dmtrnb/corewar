/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 16:01:40 by nhamill           #+#    #+#             */
/*   Updated: 2019/03/27 16:09:55 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *s)
{
	size_t		i;

	i = 0;
	if (s)
		while (*(s + i) != 0)
		{
			ft_putchar(*(s + i));
			i++;
		}
}
