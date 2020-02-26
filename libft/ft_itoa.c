/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 20:42:14 by nhamill           #+#    #+#             */
/*   Updated: 2019/04/12 22:18:09 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int num)
{
	int		i;
	int		znak;
	int		num_c;
	char	*str;

	if (num == 0)
		return (ft_strdup("0"));
	if (num == -2147483648)
		return (ft_strdup("-2147483648"));
	i = 1;
	num_c = num;
	while (num_c /= 10)
		i++;
	znak = (num < 0 ? 1 : 0);
	if (!(str = ft_strnew(i + znak)))
		return (NULL);
	*str = (znak ? '-' : 0);
	num *= (znak ? -1 : 1);
	while (num)
	{
		i--;
		*(str + i + znak) = num % 10 + 48;
		num /= 10;
	}
	return (str);
}
