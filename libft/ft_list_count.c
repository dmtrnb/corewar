/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 13:47:25 by nhamill           #+#    #+#             */
/*   Updated: 2020/01/18 13:47:47 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_list_count(t_list *list)
{
	size_t	count;
	t_list	*temp;

	count = 0;
	temp = list;
	while (temp)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}
