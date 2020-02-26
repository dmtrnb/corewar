/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 15:31:18 by nhamill           #+#    #+#             */
/*   Updated: 2019/03/29 21:32:09 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long long	ft_power(int base, int exp)
{
	unsigned long long	num;

	num = 1;
	if (exp >= 0)
		while (exp)
		{
			num *= base;
			exp--;
		}
	else
		return (0);
	return (num);
}

static char					*ft_fract(double num, char base, char precision)
{
	char	i;
	char	*str;

	if (!precision || !(str = ft_strnew(precision + 1)))
		return (NULL);
	*str = '.';
	i = 1;
	while (precision)
	{
		num *= base;
		*(str + i) = ((char)num > 9 ? (char)num + 55 : (char)num + 48);
		num -= (char)num;
		precision--;
		i++;
	}
	return (str);
}

static char					*ft_whole(unsigned long long num, char znak, \
																char base)
{
	char	mod;
	char	exp;
	char	*str;

	if (!num)
	{
		str = ft_strnew(znak + 1);
		*str = (znak ? '-' : 0);
		*(str + znak) = 48;
		return (str);
	}
	exp = 0;
	while (num > ft_power(base, exp))
		exp++;
	if (!(str = ft_strnew(exp + znak)))
		return (NULL);
	*str = (znak ? '-' : 0);
	while (num)
	{
		exp--;
		mod = num % base;
		*(str + exp + znak) = (mod > 9 ? mod + 55 : mod + 48);
		num /= base;
	}
	return (str);
}

char						*ft_itoa_base(double num, int base, int precision)
{
	char				znak;
	char				*s1;
	char				*s2;
	char				*str;

	if (!(base > 0 && base < 37))
		return (NULL);
	znak = (num < 0 ? 1 : 0);
	num *= (num < 0 ? -1 : 1);
	s1 = ft_whole((unsigned long long)num, znak, (char)base);
	s2 = ft_fract(num - (unsigned long long)num, (char)base, (char)precision);
	str = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (str);
}
