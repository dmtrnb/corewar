/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddnum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 16:50:36 by nhamill           #+#    #+#             */
/*   Updated: 2019/03/27 18:30:34 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddnum(t_list **alst, t_list *new, size_t n)
{
	size_t	i;
	t_list	*tmp0;
	t_list	*tmp1;

	if ((*alst) && new)
	{
		tmp0 = (*alst);
		i = 0;
		while (i != n && tmp0->next)
		{
			tmp0 = tmp0->next;
			i++;
		}
		tmp1 = tmp0->next;
		tmp0->next = new;
		new->next = tmp1;
	}
}
