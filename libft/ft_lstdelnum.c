/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelnum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 16:50:36 by nhamill           #+#    #+#             */
/*   Updated: 2020/01/18 13:53:07 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelnum(t_list **alst, void (*del)(void *, size_t), size_t n)
{
	size_t	i;
	t_list	*tmp0;
	t_list	*tmp1;

	if ((*alst) && del)
	{
		tmp0 = (*alst);
		if (n && (*alst)->next)
		{
			i = 0;
			while (i < n - 1 && tmp0->next->next)
			{
				tmp0 = tmp0->next;
				i++;
			}
			tmp1 = tmp0;
			tmp0 = tmp0->next;
			tmp1->next = tmp1->next->next;
		}
		else
			(*alst) = (*alst)->next;
		(*del)(&(tmp0->data), tmp0->size);
		free(tmp0);
		tmp0 = NULL;
	}
}
