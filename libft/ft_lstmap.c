/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 16:06:14 by dholiday          #+#    #+#             */
/*   Updated: 2019/04/16 16:29:33 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_free(t_list *alst)
{
	t_list	*new;

	new = alst;
	while (new != NULL)
	{
		new = alst->next;
		free(alst);
		alst = NULL;
	}
	alst = NULL;
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new;
	t_list		*chaine;

	chaine = (t_list*)malloc(sizeof(t_list));
	if (!(lst) || !(chaine) || !(f))
		return (NULL);
	chaine = f(lst);
	lst = lst->next;
	while (lst != NULL)
	{
		if ((new = ((t_list*)malloc(sizeof(t_list)))))
		{
			*new = *f(lst);
			ft_list_push_back(chaine, new);
		}
		else
		{
			ft_free(chaine);
			return (NULL);
		}
		lst = lst->next;
	}
	return (chaine);
}
