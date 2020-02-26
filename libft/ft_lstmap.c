/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 19:34:49 by nhamill           #+#    #+#             */
/*   Updated: 2019/04/13 18:33:23 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*head;

	head = NULL;
	if (lst && f)
	{
		new = (*f)(lst);
		head = new;
		while (lst->next)
		{
			lst = lst->next;
			ft_lstaddlast(&new, (*f)(lst));
		}
	}
	return (head);
}
