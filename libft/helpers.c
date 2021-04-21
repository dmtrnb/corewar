/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 18:24:45 by dholiday          #+#    #+#             */
/*   Updated: 2019/07/31 17:47:08 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa2(unsigned long long int n, int sign)
{
	char					*str;
	int						size;
	unsigned long long int	i;
	int						k;

	k = 0;
	size = 1;
	i = n;
	if (sign == -1)
		k = 1;
	while ((i = i / 10) != 0)
		size++;
	str = (char*)malloc(sizeof(char) * (size + 1 + k));
	if (!(str))
		return (NULL);
	i = size + k - 1;
	str[0] = '-';
	str[size + k] = '\0';
	while ((int)i >= k)
	{
		str[i] = '0' + ABS((n % 10));
		n = n / 10;
		i--;
	}
	return (str);
}

char	*ft_itoa_float(double d, int z)
{
	long long int	a;
	int				i;
	char			*str;

	a = (long long int)d;
	d = d - (double)a;
	str = ft_memalloc(100);
	i = 0;
	while (d > 0 && i < z)
	{
		d = d * 10;
		str[i] = '0' + (int)d;
		i++;
		a = (int)d;
		d = d - (double)a;
	}
	return (str);
}

char	*ft_itoa_float_long(long double d, int z)
{
	long long int	a;
	int				i;
	char			*str;

	a = (long long int)d;
	d = d - (long double)a;
	str = ft_memalloc(100);
	i = 0;
	while (d > 0 && i < z)
	{
		d = d * 10;
		str[i] = '0' + (int)d;
		i++;
		a = (int)d;
		d = d - (long double)a;
	}
	return (str);
}

char	*ft_approx_guy(char *str, int a)
{
	char	*temp;
	char	*new;
	int		k;

	temp = ft_strchr(str, '.');
	if ((k = ft_strlen(temp + 1)) != a + 1)
	{
		temp = ft_memalloc(a - k + 2);
		temp = ft_memset(temp, '0', a - k + 1);
		new = ft_strjoin(str, temp);
		ft_strdel(&str);
		ft_strdel(&temp);
		return (new);
	}
	return (NULL);
}

char	*ft_approx(char *str, int a)
{
	int		i;
	char	*new;

	if ((new = ft_approx_guy(str, a)) != NULL)
		return (new);
	i = ft_strlen(str) - 1;
	if (str[i] > '4' && str[i - 1] != '.')
		if (str[i - 1] != '9')
		{
			str[i - 1] = str[i - 1] + 1;
			str[i] = '0';
		}
	while (str[i] == '9' && str[i - 1] != '.')
	{
		if (str[i - 1] != '9')
			str[i - 1] = str[i - 1] + 1;
		str[i] = '0';
		i--;
	}
	if (str[i - 1] == '.')
		(str[i] > '4') ? (str[i - 2]++) : (str[i] = '0');
	return (str);
}
