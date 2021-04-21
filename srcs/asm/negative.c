/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   negative.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2020/03/07 15:36:28 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char			*ft_negative(long long int i, int size)
{
	char	*temp;
	char	*new;

	new = ft_convert(i * -1, 2, size);
	temp = ft_add_null(new, 8 * size);
	ft_invers(temp);
	ft_plus_one(temp);
	new = ft_convert(ft_str_binar_int(temp), 16, size);
	ft_strdel(&temp);
	return (new);
}

char			*ft_add_null(char *str, int i)
{
	int		len;
	int		add;
	char	*nul;
	char	*new;

	len = ft_strlen(str);
	add = i - len;
	if (add < 0)
	{
		new = ft_strdup(str + -1 * add);
		ft_strdel(&str);
		return (new);
	}
	nul = ft_strnew(add + 1);
	nul = ft_memset(nul, '0', add);
	new = ft_strjoin(nul, str);
	ft_strdel(&nul);
	ft_strdel(&str);
	return (new);
}

void			ft_invers(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		str[i] = str[i] == '0' ? '1' : '0';
		i++;
	}
}

void			ft_plus_one(char *str)
{
	int len;

	len = ft_strlen(str);
	len--;
	while (str[len] != '0')
	{
		str[len] = '0';
		len--;
	}
	str[len] = '1';
}

long long int	ft_str_binar_int(char *str)
{
	int				len;
	long long int	sum;
	long long int	i;

	len = ft_strlen(str);
	len--;
	i = 1;
	sum = 0;
	while (len >= 0)
	{
		if (str[len] == '1')
			sum += i;
		i *= 2;
		len--;
	}
	return (sum);
}
