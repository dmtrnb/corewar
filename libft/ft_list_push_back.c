/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dholiday <dholiday@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 16:24:55 by dholiday          #+#    #+#             */
/*   Updated: 2019/04/23 19:29:05 by dholiday         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push_back(t_list *begin_list, t_list *new)
{
	t_list	*p;

	p = begin_list;
	while (p->next != NULL)
		p = p->next;
	p->next = new;
}
