/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:03:28 by dholiday          #+#    #+#             */
/*   Updated: 2019/04/10 18:22:20 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*new;
	t_list	*buf;

	if ((*alst) && del)
	{
		new = *alst;
		while (new->next != NULL)
		{
			buf = new;
			del(buf->content, buf->content_size);
			new = new->next;
			free(buf);
		}
		buf = new;
		del(buf->content, buf->content_size);
		free(buf);
		*alst = NULL;
	}
}
