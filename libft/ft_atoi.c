/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 00:09:43 by nhamill           #+#    #+#             */
/*   Updated: 2020/01/18 13:24:50 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	pow_10(int c)
{
	long long	power;

	power = 1;
	while (c > 0)
	{
		power *= 10;
		c--;
	}
	return (power);
}

int					ft_atoi(const char *str)
{
	int			znak;
	long long	num;
	size_t		i;
	size_t		j;
	size_t		len;

	i = 0;
	j = 0;
	num = 0;
	while (*(str + i) != 0 && ft_isspace(*(str + i)))
		i++;
	znak = (*(str + i) == '-' ? -1 : 1);
	if (ft_strspn(str + i, "-+"))
		i++;
	len = ft_strspn(str + i, "0123456789");
	while (j != len)
	{
		num += (*(str + i + j) - 48) * pow_10((int)len - (int)j - 1);
		if (num < 0 && znak == -1)
			return (0);
		else if (num < 0)
			return (-1);
		j++;
	}
	return (num * znak);
}
