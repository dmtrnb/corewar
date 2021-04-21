/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sum_w.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 11:44:13 by dholiday          #+#    #+#             */
/*   Updated: 2019/05/08 20:53:08 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sum_w(char const *str, char c)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			while (str[i] != c && str[i] != '\0')
				i++;
			k++;
		}
		else
			i++;
	}
	return (k);
}
