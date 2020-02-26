/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 14:02:01 by nhamill           #+#    #+#             */
/*   Updated: 2020/01/18 13:14:46 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	ft_power(int c, int base, int exp)
{
	double	num;
	double	pow;

	pow = 1;
	if (exp > 0)
		while (exp)
		{
			pow *= base;
			exp--;
		}
	else
		while (exp)
		{
			pow /= base;
			exp++;
		}
	num = (c > 47 && c < 58 ? pow * (c - 48) : pow * (c - 55));
	return (num);
}

static double	ft_back(const char *str, int i, int base)
{
	int			j;
	int			exp;
	double		num;

	j = i - 1;
	exp = 0;
	num = 0;
	while (j >= 0 && ft_isdigit_base(*(str + j), base))
	{
		num += ft_power(*(str + j), base, exp);
		j--;
		exp++;
	}
	exp = -1;
	i += (*(str + i) != 0 && *(str + i) == '.' ? 1 : 0);
	while (*(str + i) != 0 && ft_isdigit_base(*(str + i), base))
	{
		num += ft_power(*(str + i), base, exp);
		i++;
		exp--;
	}
	return (num);
}

double			ft_atoi_base(const char *str, int base)
{
	int			i;
	double		num;

	i = 0;
	while (ft_isspace(*(str + i)))
		i++;
//	znak = (*(str + i) == '-' ? -1 : 1);
	i += (*(str + i) == '-' || *(str + i) == '+' ? 1 : 0);
	while (ft_isdigit_base(*(str + i), base))
		i++;
	num = ft_back(str, i, base);
	return (num);
}
