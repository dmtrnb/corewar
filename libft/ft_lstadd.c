/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamill <nhamill@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 16:50:36 by nhamill           #+#    #+#             */
/*   Updated: 2019/03/29 21:26:52 by nhamill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if ((*alst) && new)
	{
		tmp = (*alst);
		new->next = tmp;
		(*alst) = new;
	}
	else if (!(*alst) && new)
		(*alst) = new;
}
