/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 11:21:11 by dholiday          #+#    #+#             */
/*   Updated: 2020/03/07 19:24:58 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	if (size == (size_t)-1)
		return (NULL);
	str = (char*)malloc(sizeof(char) * (size + 1));
	if (!(str))
		return (NULL);
	ft_bzero(str, size + 1);
	return (str);
}
