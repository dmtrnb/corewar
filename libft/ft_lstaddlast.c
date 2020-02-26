/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddlast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 16:50:36 by nhamill           #+#    #+#             */
/*   Updated: 2019/03/27 17:05:00 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddlast(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if ((*alst) && new)
	{
		tmp = (*alst);
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else if (!(*alst) && new)
		(*alst) = new;
}
