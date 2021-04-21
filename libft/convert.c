/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 20:06:13 by dholiday          #+#    #+#             */
/*   Updated: 2019/07/31 17:46:36 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_conv_octal(unsigned long long int n)
{
	unsigned long long int	i;
	int						k;
	char					*str;

	k = 1;
	i = n;
	while ((i = i / 8) != 0)
		k++;
	str = ft_memalloc(k + 1);
	i = 0;
	str[0] = '0';
	while (n > 0)
	{
		str[i] = '0' + n % 8;
		i++;
		n = n / 8;
	}
	ft_strrev(str);
	return (str);
}

char	*ft_conv_six(unsigned long long int n, char c)
{
	unsigned long long int	i;
	int						k;
	char					*str;

	c = c == 'x' ? 'a' : 'A';
	k = 1;
	i = n;
	while ((i = i / 16) != 0)
		k++;
	str = ft_memalloc(k + 1);
	i = 0;
	str[0] = '0';
	while (n > 0)
	{
		k = n % 16;
		str[i] = k > 9 ? c + k % 10 : '0' + k;
		i++;
		n = n / 16;
	}
	ft_strrev(str);
	return (str);
}

char	*ft_strrev(char *str)
{
	int i;
	int j;
	int c;

	i = 0;
	while (str[i])
		i++;
	j = 0;
	i = i - 1;
	while (j < i)
	{
		c = str[j];
		str[j++] = str[i];
		str[i--] = c;
	}
	return (0);
}
