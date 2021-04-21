/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wide_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 18:39:55 by dholiday          #+#    #+#             */
/*   Updated: 2020/03/07 19:33:46 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_type_p(va_list hello, t_print *info)
{
	void	*a;
	char	*str1;
	int		p;

	a = va_arg(hello, void *);
	info->number = *(int *)a;
	p = info->afterpoint == 0 ? info->nullpoint : 0;
	if (a == 0)
	{
		str1 = ft_memalloc(info->afterpoint + 1 + p);
		str1 = ft_memset(str1, '0', info->afterpoint + p);
	}
	else
		str1 = print_address_hex(a);
	return (str1);
}

char	hex_digit(int v)
{
	if (v >= 0 && v < 10)
		return ('0' + v);
	else
		return ('a' + v - 10);
}

char	*print_address_hex(void *p1)
{
	int		i;
	int		j;
	size_t	p;
	char	*str;

	str = (char *)malloc((sizeof(char) * 17));
	str = ft_memset(str, '\0', 17);
	p = (size_t)p1;
	i = (sizeof(p) << 3) - 4;
	j = 0;
	while (i >= 0)
	{
		str[j] = (hex_digit((p >> i) & 0xf));
		i -= 4;
		j++;
	}
	return (str);
}
