/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 16:32:26 by nhamill           #+#    #+#             */
/*   Updated: 2020/01/18 13:55:01 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		if (!(new->data = (void *)malloc(sizeof(void) * (content_size + 1))))
			return (NULL);
		new->data = ft_memcpy(new->data, content, content_size);
		new->size = content_size;
	}
	else
	{
		new->data = NULL;
		new->size = 0;
	}
	new->next = NULL;
	return (new);
}
