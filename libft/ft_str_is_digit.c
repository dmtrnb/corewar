/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_digit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 16:43:15 by dholiday          #+#    #+#             */
/*   Updated: 2019/11/04 14:16:10 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_is_digit(char *str)
{
	int i;

	i = 0;
	if (*str == '\0')
		return (0);
	else
		while (str[i] != '\0')
		{
			if (ft_isdigit(str[i]) == 0)
				return (0);
			i++;
		}
	return (1);
}
