/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tranc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2020/03/07 15:37:10 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_convert(long long int i, int p, int size)
{
	int		len;
	char	*str;

	if (i < 0)
		return (ft_negative(i, size));
	len = ft_size_of_str(i, p);
	str = ft_strnew(len + 1);
	ft_str_int(i, p, str);
	return (str);
}

int		ft_str_int(long long int num, long long int p, char *s)
{
	int rest;
	int k;

	rest = num % p;
	num /= p;
	if (num == 0)
	{
		s[0] = ft_digit(rest);
		return (1);
	}
	k = ft_str_int(num, p, s);
	s[k++] = ft_digit(rest);
	return (k);
}

char	ft_digit(int num)
{
	if (num < 10)
		return ('0' + num);
	else
		return ('A' + num % 10);
}

int		ft_size_of_str(long long int num, int k)
{
	unsigned long long int	p;
	int						i;

	i = 1;
	p = k;
	while (num / p != 0)
	{
		i++;
		p *= k;
	}
	return (i);
}
