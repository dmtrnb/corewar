/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfold.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 20:42:33 by nhamill           #+#    #+#             */
/*   Updated: 2020/01/18 13:54:05 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstfold(t_list *lst, void *(f)(void *el1, void *el2))
{
	void	*tmp;

	if (!lst)
		return (NULL);
	if (lst && !lst->next)
		return (lst->data);
	if (lst && lst->next)
		tmp = f(lst->data, lst->next->data);
	if (!!(lst = lst->next->next))
		while (lst)
		{
			tmp = f(tmp, lst->data);
			lst = lst->next;
		}
	return (tmp);
}
