/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 16:43:47 by dholiday          #+#    #+#             */
/*   Updated: 2019/04/09 15:53:19 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	int		size;
	int		i;
	int		k;

	k = 0;
	size = 1;
	i = n;
	if (n < 0)
		k = 1;
	while ((i = i / 10) != 0)
		size++;
	str = (char *)malloc(sizeof(char) * (size + 1 + k));
	if (!(str))
		return (NULL);
	i = size + k - 1;
	str[0] = '-';
	str[size + k] = '\0';
	while (i >= k)
	{
		str[i] = '0' + ABS((n % 10));
		n = n / 10;
		i--;
	}
	return (str);
}
